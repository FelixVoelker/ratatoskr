#include "SimpleVariationSource.h"
#include "SimpleIndividual.h"

SimpleVariationSource::SimpleVariationSource(Session &session)
        : VariationSource(session) {}

unsigned long SimpleVariationSource::expectedSources() const { return 0; }

std::vector<Individual *> SimpleVariationSource::perform(std::vector<Individual *> &parents, unsigned int epoch, Thread &thread) const {
    for (auto *p : parents) {
        dynamic_cast<SimpleIndividual *>(p)->setLabel("bred");
    }
    return parents;
}