#include "Breeder.h"

Breeder::Breeder(const core::Configuration &configuration, BreedingOperator &variation_tree, unsigned int &epoch)
        : Singleton(configuration),
          varythreads(std::vector<Thread *>(configuration.getBreederConfiguration().threads))
{
    this->variation_tree = variation_tree.clone();
    unsigned int onset  = 0;
    unsigned int offset = configuration.getProblemConfiguration().popsize / configuration.getBreederConfiguration().threads;
    for (unsigned int k = 0; k < varythreads.size() - 1; k++) {
        varythreads.at(k) = new Thread(onset, offset, epoch);
        onset += offset;
    }
    varythreads.at(varythreads.size() - 1) = new Thread(onset, configuration.getProblemConfiguration().popsize - onset , epoch);
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
        std::vector<Individual *> offspring = variation_tree->vary(parents, thread);
        if (thread.getChunkOnset() + thread.getChunkOffset() < thread.getChunkOnset() + k + offspring.size()) {
            survivors = thread.getChunkOffset() - k;
            for (unsigned int l = 0; l < survivors; l++) {
                unsigned int index = thread.random.sampleIntFromUniformDistribution(static_cast<unsigned int>(offspring.size()));
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

