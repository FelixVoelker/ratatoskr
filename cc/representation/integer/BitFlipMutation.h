#ifndef RATATOSKR_BITFLIPMUTATION_H
#define RATATOSKR_BITFLIPMUTATION_H


#include "../../../core/representation/MutationOperator.h"

/**
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   13.10.2018
 */
class BitFlipMutation : public MutationOperator {

public:
    void operator()(Genotype &genotype, Thread &thread) const override;

};


#endif //RATATOSKR_BITFLIPMUTATION_H
