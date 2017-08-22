#include <thread>
#include <iostream>
#include "Evaluator.h"

Evaluator::Evaluator(Session &session) : Singleton(session), problem(session.problem()) {
    evalthreads = session.evalthreads;
}

void Evaluator::evaluateChunk(vector<Individual *> &individuals, unsigned int offset, unsigned int size) {
    for (unsigned int k = offset; k < offset + size; k++) {
        problem.evaluate(*individuals.at(k));
    }
}

void Evaluator::evaluatePopulation(Population &pop) {
    vector<Individual *> &individuals = pop.getIndividuals();
    vector<thread> threads(evalthreads);

    unsigned int offset = 0;
    auto chunk_size = static_cast<unsigned int>(individuals.size() / evalthreads);
    for (int k = 0; k < evalthreads - 1; k++) {
        threads.at(k) = thread( [this, &individuals, offset, chunk_size] {
            evaluateChunk(individuals, offset, chunk_size);
        } );
        offset += chunk_size;
    }
    threads.at(threads.size() - 1) = thread( [this, &individuals, offset, chunk_size] {
                evaluateChunk(individuals, offset, static_cast<unsigned int>(individuals.size() - offset));
            });

    for (int k = 0; k < threads.size(); k++) {
        threads.at(k).join();
    }
}