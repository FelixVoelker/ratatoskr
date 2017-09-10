#ifndef NDEC_EVALUATOR_H
#define NDEC_EVALUATOR_H


#include <thread>
#include "EvolutionaryNetwork.h"

/**
 * Represents the evaluator of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   15.07.2017
 */
class Evaluator : public Singleton {

private:
    const Problem &problem;

    unsigned int evalthreads;
    vector<thread> *threads;

    EvolutionaryNetwork *network;

    /**
     * Evaluates a given chunk of the population only. This function is called by each of the evaluation threads
     * and performs an evaluation of the individuals in the chunk.
     * @param individuals The population's individuals.
     * @param offset      Index to start with the evaluation.
     * @param size        Size of the chunk.
     */
    void evaluateChunk(vector<Individual *> &individuals, unsigned int offset, unsigned int size) const;

public:
    explicit Evaluator(const Session &session);
    ~Evaluator();

    /**
     * Evaluates an entire population.
     * @param pop State of evolutionary system's population.
     */
    void evaluatePopulation(const Population &pop) const;

};


#endif //NDEC_EVALUATOR_H
