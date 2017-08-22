#include <iostream>
#include "BreedingOperator.h"

BreedingOperator::ZeroSourcesException::ZeroSourcesException()
        : runtime_error("BreedingOperator needs at least one source.") {}

BreedingOperator::BreedingOperator(Session &session) : VariationSource(session) {}

void BreedingOperator::connect(vector<VariationSource *> sources) {
    try {
        if (sources.size() == 0)
            throw ZeroSourcesException();
        else
            VariationSource::connect(sources);
    } catch (ZeroSourcesException &e) {
        cout << e.what() << endl;
        exit(1);
    }
}

vector<Individual *> BreedingOperator::perform(Population &pop, vector<Individual *> parents, Randomizer &random) {
    vector<Individual *> offspring = breed(parents, random);
    for (auto ind : parents)
        delete ind;
    return offspring;
}
