#include <iostream>
#include "BreedingOperator.h"

BreedingOperator::ZeroSourcesException::ZeroSourcesException()
        : runtime_error("BreedingOperator needs at least one source.") {}

BreedingOperator::BreedingOperator(const Session &session) : VariationSource(session) {}

void BreedingOperator::connect(vector<VariationSource *> &sources) {
    try {
        if (sources.empty())
            throw ZeroSourcesException();
        else
            VariationSource::setup(sources);
    } catch (ZeroSourcesException &e) {
        cout << e.what() << endl;
        exit(1);
    }
}

vector<Individual *> BreedingOperator::perform(vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const {
    return breed(parents, random);
}
