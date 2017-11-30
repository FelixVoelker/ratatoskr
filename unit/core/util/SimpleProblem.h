#ifndef RATATOSKR_UNIT_SIMPLEPROBLEM_H
#define RATATOSKR_UNIT_SIMPLEPROBLEM_H


#include "../../../core/evaluation/Problem.h"

/**
 * A simple problem to test all core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   26.11.2017
 */
class SimpleProblem : public Problem {

public:
    explicit SimpleProblem(unsigned int popsize);

    void eval(Individual &individual) const override;

    SimpleProblem * clone() const;
};


#endif //RATATOSKR_UNIT_SIMPLEPROBLEM_H
