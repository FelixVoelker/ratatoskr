#include "TestVariationSource.h"

TestVariationSource::TestVariationSource(Session &session) : VariationSource(session) {}

unsigned long TestVariationSource::expectedSources() const { return 1; }

vector<Individual *> TestVariationSource::perform(vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const {
    return vector<Individual *>();
}