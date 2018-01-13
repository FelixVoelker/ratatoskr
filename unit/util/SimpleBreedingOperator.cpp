#include "SimpleBreedingOperator.h"
SimpleBreedingOperator::SimpleBreedingOperator(const core::Configuration &configuration) : BreedingOperator(configuration) {}

std::vector<Individual *>& SimpleBreedingOperator::breed(std::vector<Individual *> &parents, Thread &thread) const {
    auto *offsprings = new std::vector<Individual *>(1);
    offsprings->at(0) = parents.at(0)->clone();
    return *offsprings;
}


unsigned long SimpleBreedingOperator::expectedSources() const {
    return 1;
}