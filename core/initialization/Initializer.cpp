#include "Initializer.h"

Initializer::Initializer(const core::Configuration &configuration, Builder *builder, unsigned int &epoch)
        : Singleton(configuration),
          initthreads(std::vector<Thread *>(configuration.getInitializerConfiguration().threads))
{
    this->builder = builder;
    unsigned int onset  = 0;
    unsigned int offset = configuration.getProblemConfiguration().popsize / configuration.getInitializerConfiguration().threads;
    for (unsigned int k = 0; k < initthreads.size() - 1; k++) {
        initthreads.at(k) = new Thread(onset, offset, epoch);
        onset += offset;
    }
    initthreads.at(initthreads.size() - 1) = new Thread(onset, configuration.getProblemConfiguration().popsize - onset , epoch);
}

Initializer::~Initializer() {
    std::vector<Thread *>().swap(initthreads);
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
        individuals.at(k + thread.getChunkOnset()) = builder->build(thread);
    }
}