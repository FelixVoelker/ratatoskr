#ifndef RATATOSKR_VARIATIONSOURCE_H
#define RATATOSKR_VARIATIONSOURCE_H


#include <vector>
#include <random>
#include <stdexcept>
#include "../util/Singleton.h"
#include "../representation/Population.h"

/**
 * The blueprint class for all variation sources that form the basic elements of variation pipelines in NDEC.
 * Each source defines a particular genetic operator and selects its Genetic Operation Parameters (GOPs) randomly.
 * Therefore, its assembling variation pipeline builds delivers the components for a variation control of
 * the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   29.12.2017
 */
class VariationSource : public Singleton {

public:
    explicit VariationSource(const Session &session, std::vector<VariationSource *> &source);
    ~VariationSource();

    /**
     * Creates offspring individuals by varying the individuals of the current population recursively, i.e.
     * the source's genetic operation is performed with individuals from the previous layer of
     * the variation pipeline.
     * @param pop Current state of the evolutionary system's population.
     * @return
     */
    std::vector<Individual *> vary(std::vector<Individual *> &parents, unsigned int epoch) const;

protected:
    std::vector<VariationSource *> sources;

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
    virtual std::vector<Individual *> perform(std::vector<Individual *> &parents, unsigned int epoch) const = 0;

private:
    /**
     * An exception that is thrown if a variation source is not initialized correctly.
     */
    class InitializationException : public std::runtime_error {

    public:
        InitializationException(unsigned long sources, unsigned long expected);

    };

};


#endif //RATATOSKR_VARIATIONSOURCE_H
