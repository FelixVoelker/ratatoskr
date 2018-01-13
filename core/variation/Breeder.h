#ifndef RATATOSKR_BREEDER_H
#define RATATOSKR_BREEDER_H


#include "BreedingOperator.h"

/**
 * The core module that drives the variation phase of an Neuro-Dynamic Evolutionary Algorithm (NDEA). This variation is
 * performed on the entire population that is split into several uniformly divided chunks. These chunks are concurrently
 * processed by the variation threads whose number equals the amount of chunks.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Breeder : public Singleton {

public:
    explicit Breeder(const core::Configuration &configuration, BreedingOperator *variation_tree, unsigned int &epoch);
    ~Breeder();

    /**
     * Breeds an entire new generation of offsprings concurrently.
     * @param pop State of evolutionary system's population.
     */
    std::vector<Individual *> * breedPopulation(Population &pop) const;

protected:
    std::vector<Thread *> varythreads;

    /** Components */
    BreedingOperator *variation_tree;

    /**
     * Breeds the offspring for a given chunk of the population only. This function is called by each of the
     * variating threads and passes the chunk to the variation tree. If the tree produces too much offsprings to fit
     * into the chunk, the remaining slots are assigned randomly.
     * @param parents    The parent individuals of the current generation.
     * @param offsprings The offspring individuals of the next generation.
     * @param thread     The variating thread.
     */
    void breedChunk(std::vector<Individual *> &parents,
                    std::vector<Individual *> &offsprings,
                    Thread &thread) const;
};


#endif //RATATOSKR_BREEDER_H
