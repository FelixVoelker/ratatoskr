#ifndef RATATOSKR_EVALUATOR_H
#define RATATOSKR_EVALUATOR_H


#include "../experience/EvolutionaryNetwork.h"
#include "../representation/Population.h"

/**
 * The core module that drives the evaluation phase of an Neuro-Dynamic Evolutionary Algorithm (NDEA). This evaluation
 * is performed on the entire population that is split into several uniformly divided chunks. These chunks are
 * concurrently processed by the evaluation threads whose number equals the amount of chunks.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Evaluator : public Singleton {

public:
    explicit Evaluator(const Session &session, unsigned int &epoch);
    ~Evaluator();

    /**
     * Evaluates an entire population by estimating the fitness and cost of each individual concurrently.
     * @param pop State of evolutionary system's population.
     */
    void evaluatePopulation(Population &pop) const;

protected:
    std::vector<Thread *> evalthreads;

    /** Components */
    Problem &problem;
    EvolutionaryNetwork *network;

    /**
     * Evaluates a given chunk of the population only. This function is called by each of the evaluation threads
     * and performs the problem specific evaluation on the individuals in the chunk.
     * @param individuals The individuals within the population.
     * @param thread      The evaluating thread.
     */
    void evaluateChunk(std::vector<Individual *> &individuals, std::vector<float> costs, Thread &thread) const;

};


#endif //RATATOSKR_EVALUATOR_H
