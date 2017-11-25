#ifndef RATATOSKR_NDGAPROBLEM_H
#define RATATOSKR_NDGAPROBLEM_H


#include "../../../core/evaluation/Problem.h"
#include "../../../core/representation/Individual.h"

/**
 * TODO: Comments
 * The blueprint class for all problems to be solved by conventional Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.07.2017
 */
class NDGAProblem : public Problem {

protected:
    unsigned int genes; // Number of genes within the chromosome.

    NDGAProblem(NDGAProblem &obj);

public:
    NDGAProblem(unsigned int popsize, unsigned int genes);

    NDGAProblem * clone();
};


#endif // RATATOSKR_NDGAPROBLEM_H
