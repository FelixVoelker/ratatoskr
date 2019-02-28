#ifndef RATATOSKR_POPULATION_H
#define RATATOSKR_POPULATION_H


#include <vector>
#include "Individual.h"
#include "../../old/core/EvolutionarySystem.h"

/**
 * Represents the population as the state of an evolutionary system. Accordingly, the class incorporates a set of
 * individuals and provides the functionality for maintainance and comparison on the population level.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   15.7.2018
 */
class Population {

public:
    explicit Population(const EvolutionarySystem &system, unsigned int popsize);

    /**
     * Finds the individual with the best relevance value within the population.
     * @param fraction Decimal number within the interval [0,1] with 0 being fitness only and 1 being cost only.
     * Out of scope numbers are projected on the boundary of the interval.
     */
    const Individual bestIndividual() const;

    /**
     * Computes a new individual with the average fitness and cost value of the entire population.
     */
    const Individual averageIndividual() const;

    /**
     * Finds the individual with the worst relevance value within the population.
     * @param fraction Decimal number within the interval [0,1] with 0 being fitness only and 1 being cost only.
     * Out of scope numbers are projected on the boundary of the interval.
     */
    const Individual & worstIndividual() const;

    std::vector<Individual> & getIndividuals();

private:
    std::vector<Individual> individuals;

};


#endif //RATATOSKR_POPULATION_H
