#include "SimpleBreedingOperator.h"

std::vector<Individual *>& SimpleBreedingOperator::breed(std::vector<Individual *> &parents, Thread &thread) const {
    auto *offsprings = new std::vector<Individual *>(1);
    offsprings->at(0) = parents.at(0)->clone();
    return *offsprings;
}

SimpleBreedingOperator::SimpleBreedingOperator(Configuration &configuration) : BreedingOperator(configuration) {}

unsigned long SimpleBreedingOperator::expectedSources() const {
    return 1;
}