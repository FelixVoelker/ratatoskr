#include <iostream>
#include "Breeder.h"

Breeder::Breeder(const Session &session)
        : Singleton(session),
          popsize(session.problem().popsize()),
          varythreads(session.varythreads()) {
    variation_pipeline = session.pipeline();
    threads = new vector<thread>(varythreads);
    random = new vector<Randomizer>(varythreads);
}

Breeder::~Breeder() {
    delete threads;
    delete random;
}

void Breeder::breedChunk(vector<Individual *> &parents,
                         vector<Individual *> &offsprings,
                         const unsigned int epoch,
                         const unsigned int offset,
                         const unsigned int size,
                         const unsigned int thread) const {
    unsigned int survivors = 0;
    for (unsigned int k = offset; k < offset + size; k += survivors) {
        vector<Individual *> offspring = variation_pipeline->vary(parents, epoch, random->at(thread));
        if (offset + size < k + offspring.size()) {
            survivors = static_cast<unsigned int>(k + offspring.size() - offset - size);
            for (unsigned int l = 0; l < survivors; l++) {
                unsigned int index = random->at(thread).randomInt(offspring.size());
                offsprings.at(k + l) = offspring.at(index);
                offspring.erase(offspring.begin() + index);
            }
            for (auto o : offspring)
                delete o;
        } else {
            survivors = static_cast<unsigned int>(offspring.size());
            for (unsigned int l = 0; l < survivors; l++) {
                offsprings.at(k + l) = offspring.at(l);
            }
        }
    }
}

vector<Individual *> * Breeder::breedPopulation(const Population &pop, const unsigned int epoch) const {
    auto parents = pop.getIndividuals();
    auto offsprings = new vector<Individual *>(popsize);

    unsigned int offset = 0;
    unsigned int chunk_size = popsize / varythreads;

    vector<thread> threads(varythreads);
    for (unsigned int k = 0; k < varythreads - 1; k++) {
        threads.at(k) = thread(&Breeder::breedChunk, this, std::ref(parents), std::ref(*offsprings), epoch, offset, chunk_size, k);
        offset += chunk_size;
    }

    threads.at(varythreads - 1) = thread(&Breeder::breedChunk, this, std::ref(parents), std::ref(*offsprings), epoch, offset, popsize - offset, varythreads - 1);

    for (unsigned int k = 0; k < varythreads; k++) {
        threads.at(k).join();
    }

    return offsprings;
}