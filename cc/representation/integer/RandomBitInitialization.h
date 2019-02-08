#ifndef RATATOSKR_RANDOMBITINITIALIZATION_H
#define RATATOSKR_RANDOMBITINITIALIZATION_H


#include "../../../core/representation/InitializationOperator.h"

/**
 * An initialization operator for the binary vector genotype that assigns each gene with a binary number drawn from
 * the discrete uniform distribution U(0,1).
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   8.11.2018
 */
class RandomBitInitialization : public InitializationOperator {

public:
    void operator()(Genotype &genotype, Thread &thread) const override;

};


#endif //RATATOSKR_RANDOMBITINITIALIZATION_H
