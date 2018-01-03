#include "Evaluator.h"

Evaluator::Evaluator(const Session &session, unsigned int &epoch)
        : Singleton(session),
          evalthreads(std::vector<Thread *>(session.getEvalthreads())),
          problem(session.getProblem()),
          network(session.getNetwork())
{
    unsigned int onset  = 0;
    unsigned int offset = session.getProblem().getPopsize() / session.getEvalthreads();
    for (unsigned int k = 0; k < evalthreads.size() - 1; k++) {
        evalthreads.at(k) = new Thread(onset, offset, epoch);
        onset += offset;
    }
    evalthreads.at(evalthreads.size() - 1) = new Thread(onset, session.getProblem().getPopsize() - onset , epoch);
}

Evaluator::~Evaluator() {
    std::vector<Thread *>().swap(evalthreads);
}

void Evaluator::evaluatePopulation(Population &pop) const {
    auto &individuals = pop.getIndividuals();

    std::vector<float> costs = network->output(individuals);

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
        problem.eval(*individuals.at(k + thread.getChunkOnset()), thread);
        individuals.at(k + thread.getChunkOnset())->getCost().setCost(costs.at(k + thread.getChunkOnset()));
    }
}

