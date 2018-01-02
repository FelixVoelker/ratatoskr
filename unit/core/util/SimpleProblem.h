#ifndef RATATOSKR_UNIT_SIMPLEPROBLEM_H
#define RATATOSKR_UNIT_SIMPLEPROBLEM_H


#include "../../../core/evaluation/Problem.h"
#include "../../../core/representation/Individual.h"

/**
 * A simple instance of Problem to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class SimpleProblem : public Problem {

public:
    explicit SimpleProblem(unsigned int popsize);

    void eval(Individual &individual, Thread &thread) const override;

};


#endif //RATATOSKR_UNIT_SIMPLEPROBLEM_H
