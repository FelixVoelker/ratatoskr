#ifndef RATATOSKR_PROBLEM_H
#define RATATOSKR_PROBLEM_H


#include "../representation/Individual.h"
#include "../util/Thread.h"

/**
 * The base class for any optimization problem that is supposed to be solved by a Neuro-Dynamic Evolutionary
 * Algorithm (NDEA). These are specified by a configuration of problem-dependent parameters and an evaluation function.
 * Accordingly, a problem does not only drive the evaluation of each single individual but also assigns all
 * domain-dependent data to the components of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   7.1.2018
 */
class Problem {

public:
    explicit Problem(std::function<void(Individual &, Thread &)> eval, unsigned int popsize);
    Problem(const Problem &obj);

    std::function<void(Individual &, Thread &)> & getEval();
    Configuration::ProblemConfiguration & getConfiguration();
    void setEval(std::function<void(Individual &, Thread &)> eval);

protected:
    Configuration::ProblemConfiguration configuration;

    /**
     * Assigns a fitness value to an individual according to the specification of the problem.
     * @param individual The individual to be evaluated.
     * @param thread     The evaluating thread.
     */
    std::function<void(Individual &, Thread &)> eval;
};


#endif // RATATOSKR_PROBLEM_H
