#ifndef RATATOSKR_CORE_TESTTASK_H
#define RATATOSKR_CORE_TESTTASK_H


#include "../../../core/evaluation/Problem.h"

/**
 * An instance of Task to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestProblem : public Problem {

public:
    explicit TestProblem(unsigned int popsize);

    void eval(Individual &individual) const override;

};


#endif //RATATOSKR_CORE_TESTTASK_H
