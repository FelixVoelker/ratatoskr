#ifndef RATATOSKR_BUILDER_H
#define RATATOSKR_BUILDER_H


#include "../util/Thread.h"
#include "Genotype.h"

/**
 * The abstract base class for any initialization procedure of an individual's genotype. This functor is called during
 * the initialization phase of an evolutionary algorithm and thus works on the genetic level.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class InitializationOperator : public Clonable {

public:
    /**
     * Initializes a genotype according to the operator's strategy.
	 * @param genotype The genotype to initialize.
     * @param thread   The initializing thread.
     */
	virtual void operator()(Genotype &genotype, Thread &thread) const = 0;

};


#endif //RATATOSKR_BUILDER_H
