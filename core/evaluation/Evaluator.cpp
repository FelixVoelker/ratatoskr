#include <iostream>
#include "Evaluator.h"

Evaluator::Evaluator(const core::Configuration &configuration,
                     const EvaluationFunction &eval,
                     EvolutionaryNetwork &network)
        : Singleton(configuration),
          evalthreads(std::vector<Thread *>(configuration.getEvaluatorConfiguration().threads)),
          evals(std::vector<EvaluationFunction *>(configuration.getEvaluatorConfiguration().threads)),
          network(network)
{
    unsigned int onset  = 0;
    unsigned int offset = configuration.getProblemConfiguration().popsize / configuration.getEvaluatorConfiguration().threads;
    for (unsigned int k = 0; k < evalthreads.size() - 1; k++) {
        evalthreads.at(k) = new Thread(onset, offset);
        evals.at(k) = eval.clone();
        onset += offset;
    }
    evalthreads.at(evalthreads.size() - 1) = new Thread(onset, configuration.getProblemConfiguration().popsize - onset);
    evals.at(evalthreads.size() - 1) = eval.clone();
}

Evaluator::~Evaluator() {
    for (auto *thread : evalthreads)
        delete thread;
    std::vector<Thread *>().swap(evalthreads);

    for (auto *eval : evals)
        delete eval;
    std::vector<EvaluationFunction *>().swap(evals);
}

void Evaluator::evaluatePopulation(Population &pop) const {
    auto &individuals = pop.getIndividuals();

    std::vector<float> costs = network.output(individuals);

    std::vector<std::thread> threads(evalthreads.size());
    for (unsigned int k = 0; k < evalthreads.size(); k++) {
        threads.at(k) = std::thread(&Evaluator::evaluateChunk, this, std::ref(*evals.at(k)),
                                    std::ref(individuals), costs, std::ref(*evalthreads.at(k)));
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void Evaluator::evaluateChunk(EvaluationFunction &eval, std::vector<Individual *> &individuals, std::vector<float> costs, Thread &thread) const {
    for (unsigned int k = 0; k < thread.getChunkOffset(); k++) {
        eval(*individuals.at(k + thread.getChunkOnset()), thread);
        individuals.at(k + thread.getChunkOnset())->getRelevance().setCost(costs.at(k + thread.getChunkOnset()));
    }
}
