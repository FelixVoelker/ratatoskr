#ifndef RATATOSKR_CORE_TESTBREEDINGOPERATOR_H
#define RATATOSKR_CORE_TESTBREEDINGOPERATOR_H


#include "../../../core/variation/BreedingOperator.h"

/**
 * An instance of BreedingOperator to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestBreedingOperator : public BreedingOperator {

protected:
    unsigned long expectedSources() const override;

public:
    explicit TestBreedingOperator(Session &session);

    vector<Individual *> & breed(vector<Individual *> &parents, Randomizer &random) const override;

};


#endif //RATATOSKR_CORE_TESTBREEDINGOPERATOR_H
