#ifndef RATATOSKR_BITFLIPMUTATION_H
#define RATATOSKR_BITFLIPMUTATION_H


#include "../../../../core/representation/MutationOperator.h"

/**
 * A mutation operator for the binary vector genotype that flips each bit if a random number does not exceed the
 * threshold given by the mutationrate parameter.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   8.11.2018
 */
class BitFlipMutation : public MutationOperator {

public:
    void operator()(Genotype &genotype, Thread &thread) const override;

};


#endif //RATATOSKR_BITFLIPMUTATION_H
