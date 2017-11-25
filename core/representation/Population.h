#ifndef NDEC_POPULATION_H
#define NDEC_POPULATION_H


#include <vector>
#include "../initialization/Builder.h"


/**
 * TODO: Comments
 * Represents the state of the evolutionary system. The class organizes a set of individuals as a
 * population and provides the functionality to maintain it as well as compare several individuals with each other.
 * Furthermore, it ensures the modularization with respect to the representation's builder and individuals.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   5.7.2017
 */
class Population : public Singleton {

private:
    Builder *builder;

    vector<Individual *> individuals;

public:
    explicit Population(const Session &session);

    /**
     * Populates the evolutionary system's population by calling the given Builder.
     * This creates entirely fresh individuals.
     */
    void initialize();

    /**
     * Cleans up the entire population.
     */
    void finalize();

    /**
     * Changes the population from one generation to the next.
     */
    void changeGeneration(vector<Individual *> *offspring);

    /**
     * Estimates and returns the best individual within the population of the current generation according
     * to its given fitness measure.
     */
    Individual * bestIndividual() const;

    /**
    * Estimates and returns the worse individual within the population of the current generation according
    * to its given fitness measure.
    */
    Individual * worstIndividual() const;



    vector<Individual *> getIndividuals() const;

};


#endif //NDEC_POPULATION_H
