#ifndef NDEC_NDGAPROBLEM_H
#define NDEC_NDGAPROBLEM_H

#include "../../../../core/evaluation/Problem.h"


/**
 * The blueprint class for all problems to be solved by conventional Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.07.2017
 */
class NDGAProblem : public Problem {

public:
    unsigned int genes; // Number of genes within the chromosome.

    NDGAProblem(unsigned int popsize, unsigned int genes);

};


#endif //NDEC_NDGAPROBLEM_H
