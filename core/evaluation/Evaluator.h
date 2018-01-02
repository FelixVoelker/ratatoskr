#ifndef RATATOSKR_EVALUATOR_H
#define RATATOSKR_EVALUATOR_H


#include <thread>
#include "../experience/EvolutionaryNetwork.h"

/**
 * Represents the evaluator of the evolutionary system that drives the evaluation step of a neuro-dynamic evolutionary
 * algorithm. This evaluation is performed on the entire population that is split into several uniformly divided chunks.
 * These chunks are concurrently processed by the evaluation threads whose number equals the amount of chunks.
 *
 * @param popsize       The size of the population.
 * @param evalthreads   Non-zero positive number of evaluation threads.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class Evaluator : public Singleton {

private:
    // Parameters
    unsigned int popsize;
    unsigned int evalthreads;

    // Components
    const EvaluationFunction *eval;
    const EvolutionaryNetwork *network;

    // Auxilaries
    vector<thread> *threads;

    /**
     * Evaluates a given chunk of the population only. This function is called by each of the evaluation threads
     * and performs the problem specific evaluation on the individuals in the chunk.
     *
     * @param individuals The individuals within the population.
     * @param offset      Starting index of the chunk.
     * @param size        Size of the chunk.
     */
    void evaluateChunk(vector<Individual *> &individuals, unsigned int offset, unsigned int size) const;

public:
    explicit Evaluator(const Session &session);
    ~Evaluator();

    /**
     * Evaluates an entire population by estimating the fitness and cost of each individual concurrently.
     * @param pop State of evolutionary system's population.
     */
    void evaluatePopulation(const Population &pop) const;

};


#endif //RATATOSKR_EVALUATOR_H
