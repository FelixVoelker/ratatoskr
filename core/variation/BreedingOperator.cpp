#include <iostream>
#include "BreedingOperator.h"

BreedingOperator::BreedingOperator(Configuration &configuration) : VariationSource(configuration) {}

void BreedingOperator::setup(std::vector<VariationSource *> &sources) {
    try {
        if (sources.empty())
            throw InitializationException("Breeding operator has zero sources but needs at least one.");
        else
            VariationSource::setup(sources);
    } catch (InitializationException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

std::vector<Individual *> BreedingOperator::perform(std::vector<Individual *> &parents, Thread &thread) const {
    return breed(parents, thread);
}
