#ifndef RATATOSKR_UNIFORMCROSSOVER_H
#define RATATOSKR_UNIFORMCROSSOVER_H


#include "../../../../core/representation/RecombinationOperator.h"

/**
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   13.10.2018
 */
class UniformCrossover : public RecombinationOperator {

public:
    double p = 0.5;

    void operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const override;

protected:
    UniformCrossover(const UniformCrossover &obj);

};


#endif //RATATOSKR_UNIFORMCROSSOVER_H
