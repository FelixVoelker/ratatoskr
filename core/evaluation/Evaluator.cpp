#include <thread>
#include <iostream>
#include <boost/python.hpp>
#include "Evaluator.h"

using namespace boost::python;

Evaluator::Evaluator(Session &session) : Singleton(session), problem(session.problem()) {
    evalthreads = session.evalthreads();
}

void Evaluator::evaluateChunk(vector<Individual *> &individuals, unsigned int offset, unsigned int size) {
    for (unsigned int k = offset; k < offset + size; k++) {
        try {
            problem.evaluate(*individuals.at(k));
        } catch(const error_already_set&) {
            PyErr_Print();
        }
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