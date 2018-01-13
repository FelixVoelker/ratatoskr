#ifndef RATATOSKR_BUILDER_H
#define RATATOSKR_BUILDER_H


#include "../representation/Individual.h"
#include "../util/Thread.h"

/**
 * The abstract base class of a population's builder that initializes each individual of an evolutionary system. Rather
 * than initializing the entire population, a builder builds single individuals based of a given prototype.
 * Any Neuro-Dynamic Evolutionary Algorithm (NDEA) has to take this requirement into account.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Builder : public Singleton {

public:
    explicit Builder(const core::Configuration &configuration, Individual *prototype);
    ~Builder();

    /**
     * Builds a new individual by cloning the prototype then initializing it.
     * @param thread The initializing thread.
     */
    Individual * build(Thread &thread) const;

protected:
    Individual *prototype;

    /**
    * Initializes an individual according to the builder's strategy.
    * @param individual The individual to be initialized.
    * @param thread     The initializing thread.
    */
    virtual void initialize(Individual &individual, Thread &thread) const = 0;
};


#endif //RATATOSKR_BUILDER_H
