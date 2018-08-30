#ifndef RATATOSKR_MUTATIONOPERATOR_H
#define RATATOSKR_MUTATIONOPERATOR_H


#include "Genotype.h"
#include "VariationOperator.h"
#include "../util/Thread.h"

/**
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   12.7.2018
 */
class MutationOperator : public VariationOperator {

public:
    virtual void mutate(Genotype &genotype, Thread &thread) = 0;

};


#endif //RATATOSKR_MUTATIONOPERATOR_H
