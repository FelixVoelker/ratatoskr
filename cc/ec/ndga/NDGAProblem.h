#ifndef RATATOSKR_NDGAPROBLEM_H
#define RATATOSKR_NDGAPROBLEM_H


#include "../../../core/evaluation/Problem.h"
#include "../../../core/representation/Individual.h"

/**
 * The abstract base class for any optimization problem that is supposed to be solved
 * by a Neuro-Dynamic Genetic Algorithm (NDGA).
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   3.1.2018
 */
class NDGAProblem : public Problem {

public:
    /**
     * @param popsize Number of individuals within the population.
     * @param genes   Number of genes within each individual;
     */
    NDGAProblem(unsigned int popsize, unsigned int genes);
    NDGAProblem(const NDGAProblem &obj);

    unsigned int getGenes();
    void setGenes(unsigned int genes);

protected:
    unsigned int genes;

};


#endif //RATATOSKR_NDGAPROBLEM_H
