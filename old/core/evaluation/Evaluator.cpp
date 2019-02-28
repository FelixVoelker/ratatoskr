#include <iostream>
#include <thread>
#include "Evaluator.h"

Evaluator::Evaluator(const core::Configuration &configuration,
                     const EvaluationFunction &eval,
                     EvolutionaryNetwork &network)
        : Singleton(configuration),
          evalthreads(std::vector<Thread *>(configuration.getEvaluatorConfiguration().threads)),
          eval(eval.clone()),
          network(network)
{
    unsigned int onset  = 0;
    unsigned int offset = configuration.getProblemConfiguration().popsize / configuration.getEvaluatorConfiguration().threads;
    for (unsigned int k = 0; k < evalthreads.size() - 1; k++) {
        evalthreads.at(k) = new Thread(k, onset, offset);
        onset += offset;
    }
    evalthreads.at(evalthreads.size() - 1) = new Thread(evalthreads.size() - 1, onset, configuration.getProblemConfiguration().popsize - onset);
}

Evaluator::~Evaluator() {
    delete eval;

    for (auto *thread : evalthreads)
        delete thread;
    std::vector<Thread *>().swap(evalthreads);
}

void Evaluator::evaluatePopulation(Population &pop) const {
    auto &individuals = pop.getIndividuals();

    std::vector<float> costs = network.output(individuals);

    std::vector<std::thread> threads(evalthreads.size());
    for (unsigned int k = 0; k < evalthreads.size(); k++) {
        threads.at(k) = std::thread(&Evaluator::evaluateChunk, this, std::ref(individuals), costs, std::ref(*evalthreads.at(k)));
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void Evaluator::evaluateChunk(std::vector<Individual *> &individuals, std::vector<float> costs, Thread &thread) const {
    for (unsigned int k = 0; k < thread.getChunkOffset(); k++) {
        eval->operator()(*individuals.at(k + thread.getChunkOnset()), thread);
        individuals.at(k + thread.getChunkOnset())->getRelevance().setCost(costs.at(k + thread.getChunkOnset()));
    }
}
