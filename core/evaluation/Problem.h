#ifndef NDEC_PROBLEM_H
#define NDEC_PROBLEM_H


class Individual;

/**
 * The blueprint class for any problem that has to be solved by a run of the evolutionary system. It contains all
 * problem-dependent information for each component of NDEC.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   8.8.2017
 */
class Problem {

public:
    unsigned int popsize; // Size of the population.

    explicit Problem(unsigned int popsize);

    /**
     * Evaluates a given individual according to the user specified strategy.
     * @param individual Individual to be evaluated.
     */
    virtual void evaluate(Individual &individual) = 0;

};


#endif //NDEC_PROBLEM_H
