#ifndef RATATOSKR_RANDOMINITIALIZATION_H
#define RATATOSKR_RANDOMINITIALIZATION_H


#include "../../../core/representation/InitializationOperator.h"

/**
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   13.10.2018
 */
class RandomBitInitialization : public InitializationOperator {

public:
    void operator()(Genotype &genotype, Thread &thread) const override;

};


#endif //RATATOSKR_RANDOMINITIALIZATION_H
