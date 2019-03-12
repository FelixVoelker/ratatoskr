#ifndef RATATOSKR_MUTATIONOPERATOR_H
#define RATATOSKR_MUTATIONOPERATOR_H


#include "VariationOperator.h"

/**
 * The abstract base class for mutation operators as commonly used by evolutionary algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class MutationOperator : public VariationOperator {

public:
	float mutationrate = 0.01;

	unsigned int numParents() const override;
	unsigned int numOffspring() const override;

	std::vector<Genotype *> vary(std::vector<Genotype *> &genotypes, Thread &thread) const override;

protected:
    /**
     * Mutates the given genotype according to the operator's strategy.
     * @param genotype The genotype to mutate.
     * @param thread   The varying thread.
     */
	virtual void operator()(Genotype &genotype, Thread &thread) const = 0;

};


#endif //RATATOSKR_MUTATIONOPERATOR_H