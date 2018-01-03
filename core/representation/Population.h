#ifndef RATATOSKR_POPULATION_H
#define RATATOSKR_POPULATION_H


#include <vector>
#include "Individual.h"

/**
 * Represents the population as the state of an evolutionary system. Accordingly, the class incorporates a set of
 * individuals and provides the functionality for maintainance and comparison on the population level.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Population : public Singleton {

public:
    explicit Population(const Session &session);
    ~Population();

    /**
     * Exterminates each individual within the population.
     */
    void exterminate();

    /**
     * Finds the individual with the best fitness value within the population.
     */
    Individual * bestIndividual() const;

    /**
     * Computes a new individual with the average fitness and cost value of the entire population.
     */
    Individual * averageIndividual() const;

    /**
     * Finds the individual with the worst fitness value within the population.
     */
    Individual * worstIndividual() const;

    std::vector<Individual *> & getIndividuals();
    void setIndividuals(std::vector<Individual *> &individuals);

private:
    std::vector<Individual *> individuals;

};


#endif //RATATOSKR_POPULATION_H
