#include <thread>
#include "Breeder.h"
#include "../experience/ReplayMemory.h"

Breeder::Breeder(const core::Configuration &configuration, ReplayMemory &replay_memory, BreedingOperator &variation_tree)
        : Singleton(configuration),
          replay_memory(replay_memory),
          varythreads(std::vector<Thread *>(configuration.getBreederConfiguration().threads))
{
    this->variation_tree = variation_tree.clone();
    unsigned int onset  = 0;
    unsigned int offset = configuration.getProblemConfiguration().popsize / configuration.getBreederConfiguration().threads;
    for (unsigned int k = 0; k < varythreads.size() - 1; k++) {
        varythreads.at(k) = new Thread(k, onset, offset);
        onset += offset;
    }
    varythreads.at(varythreads.size() - 1) = new Thread(varythreads.size() - 1, onset, configuration.getProblemConfiguration().popsize - onset);
}

Breeder::~Breeder() {
    for (auto *thread : varythreads)
        delete thread;
    std::vector<Thread *>().swap(varythreads);

    delete variation_tree;
}

std::vector<Individual *> * Breeder::breedPopulation(Population &pop) const {
    auto &parents = pop.getIndividuals();
    auto offsprings = new std::vector<Individual *>(parents.size());

    std::vector<std::thread> threads(varythreads.size());
    for (unsigned int k = 0; k < varythreads.size(); k++) {
        threads.at(k) = std::thread(&Breeder::breedChunk, this, std::ref(parents), std::ref(*offsprings), std::ref(*varythreads.at(k)));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    return offsprings;
}

void Breeder::breedChunk(std::vector<Individual *> &parents,
                         std::vector<Individual *> &offsprings,
                         Thread &thread) const {
    unsigned int survivors = 0;
    for (unsigned int k = 0; k < thread.getChunkOffset(); k += survivors) {
        auto record = std::vector<Individual *>();
        std::vector<Individual *> offspring = variation_tree->vary(parents, record, thread);
        replay_memory.record(record, offspring, thread);
        if (thread.getChunkOnset() + thread.getChunkOffset() < thread.getChunkOnset() + k + offspring.size()) {
            survivors = thread.getChunkOffset() - k;
            for (unsigned int l = 0; l < survivors; l++) {
                unsigned int index = thread.random.uniformlyChoose(static_cast<unsigned int>(offspring.size()));
                offsprings.at(thread.getChunkOnset() + k + l) = offspring.at(index);
                offspring.erase(offspring.begin() + index);
            }
            for (auto o : offspring) {
                delete o;
            }
        } else {
            survivors = static_cast<unsigned int>(offspring.size());
            for (unsigned int l = 0; l < survivors; l++) {
                offsprings.at(thread.getChunkOnset() + k + l) = offspring.at(l);
            }
        }
    }
}

