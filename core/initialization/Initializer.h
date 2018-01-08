#ifndef RATATOSKR_INITIALIZER_H
#define RATATOSKR_INITIALIZER_H


#include "Builder.h"
#include "../representation/Population.h"
#include "../util/Thread.h"

/**
 * The core module that drives the initialization phase of an Neuro-Dynamic Evolutionary Algorithm (NDEA).
 * This initialization is performed on the entire population that is split into several uniformly divided chunks.
 * These chunks are concurrently processed by the initialization threads whose number equals the amount of chunks.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Initializer : public Singleton {

public:
    explicit Initializer(Configuration &configuration, Builder *builder, unsigned int &epoch);
    ~Initializer();

    /**
     * Initializes an entire population by building each individual concurrently.
     * @param pop State of evolutionary system's population.
     */
    void initializePopulation(Population &pop);

protected:
    std::vector<Thread *> initthreads;

    /** Components */
    Builder *builder;

    /**
     * Initializes a given chunk of the population only. This function is called by each of the initialization threads
     * and calls the evolutionary system's builder for each slot in the chunk.
     * @param individuals The individuals within the population.
     * @param thread      The initializing thread.
     */
    void initializeChunk(std::vector<Individual *> &individuals, Thread &thread);
};


#endif //RATATOSKR_INITIALIZER_H
