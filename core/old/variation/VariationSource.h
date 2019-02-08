#ifndef RATATOSKR_VARIATIONSOURCE_H
#define RATATOSKR_VARIATIONSOURCE_H


#include <vector>
#include <stdexcept>
#include "../util/Singleton.h"
#include "../../state/Population.h"
#include "../../util/Thread.h"

/**
 * The abstract base class for all variation sources that form the nodes of a variation tree, i.e. a structure that
 * breeds offspring according to the genetic operations in a Neuro-Dynamic Evolutionary Algorithm (NDEA) and therefore
 * contributes to the assembly of variation controls for the evolutionary system. Each source defines a particular
 * genetic operation and selects its parameters randomly. However, it needs to be set up before it can be used.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   25.1.2018
 */
class VariationSource : public Prototype {

public:
    explicit VariationSource(const core::Configuration &configuration);
    ~VariationSource();

    /**
     * Sets up the variation source as the parent of the given child sources, i.e. it builds a variation tree.
     * Accordingly, calling this method is a mandatory step before the source can be used to breed offsprings.
     * @param  sources A list of child sources.
     * @throws InitializationException if the number of children does not match the expected number of sources.
     */
    virtual void setup(std::vector<VariationSource *> *sources);

    /**
     * Creates offspring individuals by varying the given parent individuals recursively, i.e. the variation source's
     * genetic operation is performed on the offspring of the child sources.
     * @param parents A list of parent individuals.
     * @param epoch   Current epoch of the evolutionary run.
     * @param thread  The variating thread.
     * @throws InitializationException if setup has not been called.
     */
    std::vector<Individual *> vary(std::vector<Individual *> &parents, std::vector<Individual *> &record, Thread &thread) const;

    virtual VariationSource * clone() const = 0;

protected:
    std::vector<VariationSource *> *sources;

    VariationSource(const VariationSource &obj);

    /**
     * Specifies the expected number of the variation source's children.
     */
    virtual unsigned long expectedSources() const = 0;

    /**
     * Performs the genetic operation that is associated with this variation source. This method is to differentiate
     * between breeding and selection operations. For internal use only.
     * @param parents A list of parent individuals.
     * @param epoch   Current epoch of the evolutionary run.
     * @param thread  The variating thread.
     */
    virtual std::vector<Individual *> perform(std::vector<Individual *> &parents, Thread &thread) const = 0;

    /**
     * An exception that is thrown if a variation source is not initialized correctly.
     *
     * @author  FelixVoelker
     * @version 0.0.2
     * @since   30.12.2017
     */
    class InitializationException : public std::runtime_error {

    public:
        explicit InitializationException(std::string error_message);

    };

private:
    bool initialized = false;

};


#endif //RATATOSKR_VARIATIONSOURCE_H