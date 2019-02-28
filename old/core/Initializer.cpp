#include "Initializer.h"

Initializer::Initializer(Builder &builder) : builder(builder) {}

void Initializer::initializePopulation(Population &pop, std::vector<Thread> &threads) {
    auto &individuals = pop.getIndividuals();
    for (auto &thread : threads) {
        thread.task = std::thread(&Initializer::initializeChunk, this, std::ref(individuals), std::ref(thread));
    }
    for (auto &thread : threads) {
        thread.task.join();
    }
}

void Initializer::initializeChunk(std::vector<Individual *> &individuals, Thread &thread) {
    for (unsigned int k = thread.getChunkOnset(); k < thread.getChunkOffset(); k++) {
         builder.build(individuals.at(k)->getGenotype(), thread);
    }
}