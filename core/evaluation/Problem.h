#ifndef RATATOSKR_PROBLEM_H
#define RATATOSKR_PROBLEM_H


class Individual;

/**
 * The abstract base class for any optimization problem that is supposed to be solved by the evolutionary system.
 * These are specified by a set of particular parameters and an evaluation function. Accordingly, a problem does not
 * only drive the evaluation of each single individual but also designates all problem-dependent data to the components
 * of the evolutionary system.
 *
 * @param popsize The size of the population.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   25.10.2017
 */
class Problem {

protected:
    // Parameters
    unsigned int popsize;

    Problem(const Problem &obj);

public:
    explicit Problem(unsigned int popsize);

    /**
     * Assigns a fitness value to an individual according to the strategy of the task.
     * @param individual The individual to be evaluated.
     */
//    virtual void eval(Individual &individual) const = 0;

    virtual Problem * clone() const = 0;

    unsigned int getPopsize() const;
    void setPopsize(unsigned int popsize);

};


#endif // RATATOSKR_PROBLEM_H
