#ifndef RATATOSKR_RECOMBINATIONOPERATOR_H
#define RATATOSKR_RECOMBINATIONOPERATOR_H


#include "VariationOperator.h"

/**
 * The abstract base class for recombination operators as commonly used by evolutionary algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class RecombinationOperator : public VariationOperator {

public:
    float crossoverrate = 0.8;

    unsigned int numParents() const override;
    unsigned int numOffspring() const override;

    std::vector<Genotype *> vary(std::vector<Genotype *> &genotypes, Thread &thread) const override;

protected:
    /**
     * Recombines the given genotypes according to the operator's strategy.
     * @param genotype1 The first genotype to be recombined.
     * @param genotype2 The second genotype to be recombined.
     * @param thread  The varying thread.
     */
    virtual void operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const = 0;

};


#endif //RATATOSKR_RECOMBINATIONOPERATOR_H
