#include <thread>
#include <iostream>
#include "Evaluator.h"
#include "../../cc/ec/common/RawRelevance.h"

Evaluator::Evaluator(const Session &session)
        : Singleton(session),
          problem(session.problem()),
          evalthreads(session.evalthreads()) {
    network = session.network();
    threads = new vector<thread>(evalthreads);
}

Evaluator::~Evaluator() {
    delete threads;
}

void Evaluator::evaluateChunk(vector<Individual *> &individuals, const unsigned int offset, const unsigned int size) const {
    for (unsigned int k = offset; k < offset + size; k++)
        problem.evaluate(*individuals.at(k));
}

void Evaluator::evaluatePopulation(const Population &pop) const {
    vector<Individual *> individuals = pop.getIndividuals();

    unsigned int offset = 0;
    auto chunk_size = static_cast<unsigned int>(individuals.size() / evalthreads);
    for (int k = 0; k < evalthreads - 1; k++) {
        threads->at(k) = thread(&Evaluator::evaluateChunk, this, std::ref(individuals), offset, chunk_size);
        offset += chunk_size;
    }
    threads->at(evalthreads - 1) = thread(&Evaluator::evaluateChunk, this, std::ref(individuals), offset, individuals.size() - offset);

    for (auto &thread : *threads) {
        thread.join();
    }

    vector<float> cost = network->output(pop);
    for (int k = 0; k < pop.getIndividuals().size(); k++) {
        dynamic_cast<RawRelevance &>(pop.getIndividuals().at(k)->getRelevance()).cost(cost.at(k));
    }
}