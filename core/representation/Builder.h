#ifndef RATATOSKR_BUILDER_H
#define RATATOSKR_BUILDER_H


#include "../util/Thread.h"
#include "Genotype.h"

/**
 * The abstract base class for any builder of an individual's genotype. Rather than initializing the entire population,
 * a builder builds single individuals based of a given prototype.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   1.9.2018
 */
class Builder : public Clonable {

public:
    /**
     * Initializes an individual according to the builder's strategy.
     * Builds a new individual by cloning the prototype then initializing it.
     * @param thread The initializing thread.
     */
    virtual void build(Genotype &genotype, Thread &thread) const = 0;

};


#endif //RATATOSKR_BUILDER_H
