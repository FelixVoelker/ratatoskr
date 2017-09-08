#ifndef NDEC_VARIATIONSOURCE_H
#define NDEC_VARIATIONSOURCE_H


#include <vector>
#include <random>
#include <stdexcept>
#include "../util/Singleton.h"
#include "../representation/Population.h"
#include "../util/Randomizer.h"

/**
 * The blueprint class for all variation sources that form the basic elements of variation pipelines in NDEC.
 * Each source defines a particular genetic operator and selects its Genetic Operation Parameters (GOPs) randomly.
 * Therefore, its assembling variation pipeline builds delivers the components for a variation control of
 * the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   5.8.2017
 */
class VariationSource : public Singleton {

private:
    /**
     * An exception that is thrown if a variation source is not initialized correctly.
     */
    class InitializationException : public runtime_error {

    public:
        InitializationException(unsigned long sources, unsigned long expected);

    };

protected:
    vector<VariationSource *> sources;

protected:
    /**
     * Specifies the number of previous sources that the variation source expects as input.
     */
    virtual unsigned long expectedSources() const = 0;

    /**
     * Performs the genetic operation that is associated with this source. This method is to differentiate between
     * breeding and selection operations. For internal use only.
     * @param pop     Current state of the evolutionary system's population.
     * @param parents Parent individuals for the operation.
     * @return Offspring individuals.
     */
    virtual vector<Individual *> perform(vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const = 0;

public:
    explicit VariationSource(const Session &session);
    virtual ~VariationSource();

    /**
     * Connects this variation source with the sources of the previous layer.
     * @param sources
     */
    virtual void connect(vector<VariationSource *> &sources);

    /**
     * Creates offspring individuals by varying the individuals of the current population recursively, i.e.
     * the source's genetic operation is performed with individuals from the previous layer of
     * the variation pipeline.
     * @param pop Current state of the evolutionary system's population.
     * @return
     */
    vector<Individual *> vary(const vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const;

};


#endif //NDEC_VARIATIONSOURCE_H
