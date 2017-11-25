#ifndef NDEC_BREEDER_H
#define NDEC_BREEDER_H


#include <thread>
#include "../util/Singleton.h"
#include "BreedingOperator.h"
#include "../util/Randomizer.h"

/**
 * TODO: Comments
 * Represents the breeder of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   8.8.2017
 */
class Breeder : public Singleton {

private:
    const unsigned int popsize;

    const unsigned int varythreads;
    vector<thread>     *threads;
    vector<Randomizer> *random;

    BreedingOperator *variation_pipeline;

protected:
    /**
     * Breeds the offspring for a given chunk of the next population only. This function is called by each of the
     * breeding threads and performs variation for the chunk. If the pipeline produces too much offsprings to fit
     * into the chunk, the remaining slots are assigned randomly.
     * @param pop        Current state of the evolutionary system's population.
     * @param parents The next population of the system.
     * @param offset     Index to start adding offsprings.
     * @param size       Size of the chunk.
     * @param thread     Index of running thread.
     */
    void breedChunk(vector<Individual *> &parents,
                    vector<Individual *> &offsprings,
                    unsigned int epoch,
                    unsigned int offset,
                    unsigned int size,
                    unsigned int thread) const;

public:
    explicit Breeder(const Session &session);
    ~Breeder();

    /**
     * Breeds a generation of offsprings.
     * @param pop Current state of the evolutionary system's population.
     */
    vector<Individual *> * breedPopulation(const Population &pop, unsigned int epoch) const;

};


#endif //NDEC_BREEDER_H
