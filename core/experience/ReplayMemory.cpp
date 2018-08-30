#include "ReplayMemory.h"
#include "../../cc/common/VectorIndividual.h"

ReplayMemory::ReplayMemory(const core::Configuration &configuration) : Prototype(configuration) {
    this->chunk_size = configuration.getReplayMemoryConfiguration().chunk_size;
    unsigned int threads = configuration.getBreederConfiguration().threads;

    ready = new std::vector<bool>(threads, false);

    pointer = new std::vector<unsigned int>(threads, 0);
    onset = new std::vector<unsigned int>(threads, 0);
    offset = new std::vector<unsigned int>(threads);

    unsigned int tmp = 0;
    for (unsigned int k = 0; k < threads - 1; k++) {
        onset->at(k) = tmp;
        offset->at(k) = chunk_size / threads;
        tmp += offset->at(k);
    }
    onset->at(threads - 1) = tmp;
    offset->at(threads - 1) = chunk_size - tmp;

    fitness_memory = new std::vector<float>(chunk_size);
    parent_memory = new std::vector<std::vector<float>>(chunk_size);
    offspring_memory = new std::vector<std::vector<float>>(chunk_size);
}

ReplayMemory::~ReplayMemory() {
    delete ready;
    delete pointer;
    delete onset;
    delete offset;
    delete fitness_memory;
    delete parent_memory;
    delete offspring_memory;
}

void ReplayMemory::record(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings, Thread & thread) {
    unsigned int id = thread.getID();
    for (unsigned int k = 0; k < parents.size(); k++) {
        fitness_memory->at(onset->at(id) + pointer->at(id)) = parents.at(k)->getRelevance().getFitness();
        parent_memory->at(onset->at(id) + pointer->at(id)) = std::vector<float>(dynamic_cast<VectorIndividual *>(parents.at(k))->getChromosome());
        offspring_memory->at(onset->at(id) + pointer->at(id)) = std::vector<float>(dynamic_cast<VectorIndividual *>(offsprings.at(k))->getChromosome());
        pointer->at(thread.getID()) += 1;
        if (pointer->at(thread.getID()) % offset->at(thread.getID()) == 0) {
            pointer->at(thread.getID()) = 0;
            ready->at(thread.getID()) = true;
        }

        delete parents.at(k);
    }
}

ReplayMemory* ReplayMemory::clone() const {
    return new ReplayMemory(*this);
}

bool ReplayMemory::isReady() {
    bool is_ready = true;
    for (auto r : *ready) {
        is_ready &= r;
    }
    return is_ready;
}

unsigned int ReplayMemory::sampleIndex(Thread &thread) {
    return thread.random.sampleIntFromUniformDistribution(chunk_size);
}

float ReplayMemory::getFitnessFromSample(unsigned int index) {
    return fitness_memory->at(index);
}

std::vector<float> ReplayMemory::getParentFromSample(unsigned int index) {
    return parent_memory->at(index);
}

std::vector<float> ReplayMemory::getOffspringFromSample(unsigned int index) {
    return offspring_memory->at(index);
}

ReplayMemory::ReplayMemory(const ReplayMemory &obj) : Prototype(obj) {
    this->chunk_size = obj.chunk_size;
    this->ready = new std::vector<bool>(*obj.ready);
    this->pointer = new std::vector<unsigned int>(*obj.pointer);
    this->onset = new std::vector<unsigned int>(*obj.onset);
    this->offset = new std::vector<unsigned int>(*obj.offset);
    this->fitness_memory = new std::vector<float>(*obj.fitness_memory);
    this->parent_memory = new std::vector<std::vector<float>>(*obj.parent_memory);
    this->offspring_memory = new std::vector<std::vector<float>>(*obj.offspring_memory);
}