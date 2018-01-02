#include "Initializer.h"

Initializer::Initializer(const Session &session, unsigned int &epoch)
        : Singleton(session),
          initthreads(std::vector<Thread *>(session.getInitthreads()))
{
    builder = session.getBuilder();
    unsigned int onset  = 0;
    unsigned int offset = session.getProblem().getPopsize() / session.getInitthreads();
    for (unsigned int k = 0; k < initthreads.size() - 1; k++) {
        initthreads.at(k) = new Thread(onset, offset, epoch);
        onset += offset;
    }
    initthreads.at(initthreads.size() - 1) = new Thread(onset, session.getProblem().getPopsize() - onset , epoch);
}

Initializer::~Initializer() {
    for (auto *initthread : initthreads) {
        delete(initthread);
    }
}

void Initializer::initializePopulation(Population &pop) {
    auto &individuals = pop.getIndividuals();

    std::vector<std::thread> threads(initthreads.size());
    for (unsigned int k = 0; k < initthreads.size(); k++) {
        threads.at(k) = std::thread(&Initializer::initializeChunk, this, std::ref(individuals), std::ref(*initthreads.at(k)));
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void Initializer::initializeChunk(std::vector<Individual *> &individuals, Thread &thread) {
    for (unsigned int k = 0; k < thread.getChunkOffset(); k++) {
        individuals.at(k + thread.getChunkOnset()) = builder->build();
    }
}