#ifndef RATATOSKR_INITIALIZER_H
#define RATATOSKR_INITIALIZER_H


#include "../representation/Builder.h"
#include "../../core/state/Population.h"
#include "../../core/util/Thread.h"

/**
 * @todo: check comments
 * The core module that drives the initialization phase of an Neuro-Dynamic Evolutionary Algorithm (NDEA).
 * This initialization is performed on the entire population that is split into several uniformly divided chunks.
 * These chunks are concurrently processed by the initialization threads whose number equals the amount of chunks.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Initializer  {

public:
    explicit Initializer(Builder &builder);

    /**
     * Initializes an entire population by building each individual concurrently.
     * @param pop State of evolutionary system's population.
     */
    void initializePopulation(Population &pop, std::vector<Thread> &threads);

private:
    /** Components */
    Builder builder;

    /**
     * Initializes a given chunk of the population only. This function is called by each of the initialization threads
     * and calls the evolutionary system's builder for each slot in the chunk.
     * @param individuals The individuals within the population.
     * @param thread      The initializing thread.
     */
    void initializeChunk(std::vector<Individual *> &individuals, Thread &thread);

};


#endif //RATATOSKR_INITIALIZER_H
