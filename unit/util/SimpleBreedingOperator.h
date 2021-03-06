#ifndef RATATOSKR_UNIT_SIMPLEBREEDINGOPERATOR_H
#define RATATOSKR_UNIT_SIMPLEBREEDINGOPERATOR_H


#include "../../core/variation/BreedingOperator.h"

/**
 * A simple instance of BreedingOperator to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleBreedingOperator : public BreedingOperator {

public:
    explicit SimpleBreedingOperator(const core::Configuration &configuration);

    std::vector<Individual *> & breed(std::vector<Individual *> &parents, Thread &thread) const override;

    SimpleBreedingOperator * clone() const override;

protected:
    unsigned long expectedSources() const override;

    SimpleBreedingOperator(const SimpleBreedingOperator &obj) = default;

};


#endif //RATATOSKR_UNIT_SIMPLEBREEDINGOPERATOR_H
