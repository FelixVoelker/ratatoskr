#ifndef RATATOSKR_NPOINTCROSSOVER_H
#define RATATOSKR_NPOINTCROSSOVER_H


#include "../../../core/representation/RecombinationOperator.h"

/**
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   13.10.2018
 */
class PointCrossover : public RecombinationOperator {

public:
    explicit PointCrossover(unsigned int numPoints);

    void operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const override;

protected:
    unsigned int numPoints;

    PointCrossover(const PointCrossover &obj);

};


#endif //RATATOSKR_NPOINTCROSSOVER_H
