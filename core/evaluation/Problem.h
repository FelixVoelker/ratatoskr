#ifndef RATATOSKR_PROBLEM_H
#define RATATOSKR_PROBLEM_H


#include "../util/Thread.h"

class Individual;

/**
 * The abstract base class for any optimization problem that is supposed to be solved by the evolutionary system.
 * These are specified by a set of particular parameters and an evaluation function. Accordingly, a problem does not
 * only drive the evaluation of each single individual but also assigns all problem-dependent data to the components
 * of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Problem {

public:
    /**
     * @param popsize Number of individuals within the population.
     */
    explicit Problem(unsigned int popsize);

    /**
     * Assigns a fitness value to an individual according to the specification of the problem.
     * @param thread  The evaluating thread.
     */
    virtual void eval(Individual &individual, Thread &thread) const = 0;

    unsigned int getPopsize() const;
    void setPopsize(unsigned int popsize);

protected:
    unsigned int popsize;

    Problem(const Problem &obj);

};


#endif // RATATOSKR_PROBLEM_H
