#ifndef RATATOSKR_BUILDER_H
#define RATATOSKR_BUILDER_H


#include "../util/Thread.h"
#include "Genotype.h"

/**
 * @todo change comment
 * The abstract base class of a population's builder that initializes each individual of an evolutionary system. Rather
 * than initializing the entire population, a builder builds single individuals based of a given prototype.
 * Any Neuro-Dynamic Evolutionary Algorithm (NDEA) has to take this requirement into account.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   12.7.2018
 */
class Builder : public Clonable {

public:
    /**
     * @todo: change comment
     * Initializes an individual according to the builder's strategy.
     * Builds a new individual by cloning the prototype then initializing it.
     * @param thread The initializing thread.
     */
    virtual void build(Genotype &genotype, Thread &thread) const = 0;

};


#endif //RATATOSKR_BUILDER_H
