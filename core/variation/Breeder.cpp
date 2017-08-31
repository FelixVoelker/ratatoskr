#include <thread>
#include <iostream>
#include "Breeder.h"

Breeder::Breeder(Session &session) : Singleton(session) {
    breedthreads = session.varythreads();
    random = vector<Randomizer>(breedthreads);
    variation_pipeline = session.pipeline();
}

void Breeder::breedChunk(Population &pop,
                         vector<Individual *> &offsprings,
                         unsigned int offset,
                         unsigned int size,
                         unsigned int thread) {
    vector<Individual *> offspring(0);
    for (unsigned long k = offset; k < offset + size; k += offspring.size()) {
        offspring = (*variation_pipeline)->vary(pop, random.at(thread));
        if (size < k + offspring.size()) {
            for (unsigned int l = 0; l < k + offspring.size() - size; l++) {
                int index = random.at(thread).randomInt(offspring.size());
                offsprings.at(k + l) = offspring.at(index);
                offspring.erase(offspring.begin() + index); //TODO: Check if the pointer's object is deleted as well.
            }
        } else {
            for (unsigned int l = 0; l < offspring.size(); l++) {
                offsprings.at(k + l) = offspring.at(l);
            }
        }
    }
}

void Breeder::breedPopulation(Population &pop) {
    vector<Individual *> offsprings(pop.getIndividuals().size());
    vector<thread> threads(breedthreads);

    unsigned int offset = 0;
    unsigned int chunk_size = offsprings.size() / breedthreads;
    for (int k = 0; k < breedthreads - 1; k++) {
        threads.at(k) = thread(
                [this, &pop, &offsprings, offset, chunk_size, k] {
                    breedChunk(pop, offsprings, offset, chunk_size, k);
                });
        offset += chunk_size;
    }

    threads.at(threads.size() - 1) = thread(
            [this, &pop, &offsprings, offset, chunk_size] {
                breedChunk(pop, offsprings, offset, offsprings.size() - offset, breedthreads - 1);
            });

    for (int k = 0; k < threads.size(); k++) {
        threads.at(k).join();
    }

    for (int k = 0; k < pop.getIndividuals().size(); k++) {
        delete pop.getIndividuals().at(k);
        pop.getIndividuals().at(k) = dynamic_cast<Individual *>(offsprings.at(k)->clone());
    }
}