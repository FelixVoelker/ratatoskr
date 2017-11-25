#include "TestBreedingOperator.h"

unsigned long TestBreedingOperator::expectedSources() const {
    return 1;
}

vector<Individual *> & TestBreedingOperator::breed(vector<Individual *> &parents, Randomizer &random) const {
    return *new vector<Individual *>();
}

TestBreedingOperator::TestBreedingOperator(Session &session) : BreedingOperator(session) {}