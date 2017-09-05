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
                         unsigned int epoch,
                         unsigned int offset,
                         unsigned int size,
                         unsigned int thread) {
    vector<Individual *> offspring(0);
    for (unsigned long k = offset; k < offset + size; k += offspring.size()) {
        offspring = variation_pipeline->vary(pop, epoch, random.at(thread));
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

vector<Individual *> & Breeder::breedPopulation(Population &pop, unsigned int epoch) {
    vector<Individual *> *offsprings = new vector<Individual *>(pop.getIndividuals().size());
    vector<thread> threads(breedthreads);

    unsigned int offset = 0;
    unsigned int chunk_size = offsprings->size() / breedthreads;
    for (int k = 0; k < breedthreads - 1; k++) {
        threads.at(k) = thread(
                [this, &pop, &offsprings, epoch, offset, chunk_size, k] {
                    breedChunk(pop, *offsprings, epoch, offset, chunk_size, k);
                });
        offset += chunk_size;
    }

    threads.at(threads.size() - 1) = thread(
            [this, &pop, &offsprings, epoch, offset, chunk_size] {
                breedChunk(pop, *offsprings, epoch, offset, offsprings->size() - offset, breedthreads - 1);
            });

    for (int k = 0; k < threads.size(); k++) {
        threads.at(k).join();
    }

    vector<Individual *> *olds = new vector<Individual *>(pop.getIndividuals().size());
    for (unsigned int k = 0; k < olds->size(); k++) {
        olds->at(k) = dynamic_cast<Individual *>(pop.getIndividuals().at(k)->clone());
        pop.getIndividuals().at(k) = offsprings->at(k);
        offsprings->at(k) = nullptr;
    }
    offsprings->clear();
    return *olds;
}