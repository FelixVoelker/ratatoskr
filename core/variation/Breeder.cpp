#include <iostream>
#include "Breeder.h"

Breeder::Breeder(const Session &session)
        : Singleton(session),
          popsize(session.problem().popsize()),
          varythreads(session.varythreads()) {
    variation_pipeline = session.pipeline();
    random = vector<Randomizer>(varythreads);
}

void Breeder::breedChunk(Population &pop,
                         vector<Individual *> &parents,
                         const unsigned int epoch,
                         const unsigned int offset,
                         const unsigned int size,
                         const unsigned int thread) {
    unsigned int survivors = 0;
    for (unsigned int k = offset; k < offset + size; k += survivors) {
        vector<Individual *> offspring = variation_pipeline->vary(parents, epoch, random.at(thread));
        if (offset + size < k + offspring.size()) {
            survivors = k + offspring.size() - offset - size;
            for (unsigned int l = 0; l < survivors; l++) {
                unsigned int index = random.at(thread).randomInt(offspring.size());
                pop.getIndividuals().at(k + l) = offspring.at(index);
                offspring.erase(offspring.begin() + index);
            }
            for (auto o : offspring)
                delete o;
        } else {
            survivors = offspring.size();
            for (unsigned int l = 0; l < survivors; l++) {
                pop.getIndividuals().at(k + l) = offspring.at(l);
            }
        }
    }
}

vector<Individual *> * Breeder::breedPopulation(Population &pop, const unsigned int epoch) {
    auto parents = new vector<Individual *>(popsize);
    for (int k = 0; k < popsize; k++) {
        parents->at(k) = dynamic_cast<Individual *>(pop.getIndividuals().at(k)->clone());
    }

    unsigned int offset = 0;
    unsigned int chunk_size = popsize / varythreads;

    vector<thread> threads(varythreads);
    for (unsigned int k = 0; k < varythreads - 1; k++) {
        threads.at(k) = thread(
                [this, &pop, &parents, epoch, offset, chunk_size, k] {
                    breedChunk(pop, *parents, epoch, offset, chunk_size, k);
                });
        offset += chunk_size;
    }

    threads.at(varythreads - 1) = thread(
            [this, &pop, &parents, epoch, offset, chunk_size] {
                breedChunk(pop, *parents, epoch, offset, popsize - offset, varythreads - 1);
            });

    for (unsigned int k = 0; k < varythreads; k++) {
        threads.at(k).join();
    }

    return parents;
}