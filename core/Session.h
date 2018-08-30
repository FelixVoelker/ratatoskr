#ifndef RATATOSKR_SESSION_H
#define RATATOSKR_SESSION_H


#include "EvolutionarySystem.h"
#include "TerminationCondition.h"


/**
 * @todo change comments
 * The base class for any Neuro-Dynamic Evolutionary Algorithm (NDEA) that can be run. A session builds the
 * evolutionary system of the desired method by setting up all necessary parameters for every component. It requires
 * the problem to be solved in order to extract the problem-dependent specifications. However, it hides all method
 * specific parameters to make the building process more convenient.
 *
 * @author  FelixVoelker
 * @version 0.1.1
 * @since   14.7.2018
 */

class Session {

public:
    unsigned int popsize = 200;

    unsigned int initthreads = 3;
    unsigned int evalthreads = 3;
    unsigned int varythreads = 3;

    explicit Session(const EvolutionarySystem &system);

    /**
     * Runs consecutive episodes of the evolutionary system until the total number of epochs has been processed.
     */
    void run(TerminationCondition &condition);

    Statistics & getStatistics();

private:
    const EvolutionarySystem &system;

    Statistics statistics;

    std::vector<Thread> buildThreads(unsigned int n_threads);

};


#endif //RATATOSKR_SESSION_H
