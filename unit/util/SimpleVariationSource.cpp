#include "SimpleVariationSource.h"
#include "SimpleIndividual.h"

SimpleVariationSource::SimpleVariationSource(const core::Configuration &configuration)
        : VariationSource(configuration) {}

SimpleVariationSource* SimpleVariationSource::clone() const {
    return new SimpleVariationSource(*this);
}

unsigned long SimpleVariationSource::expectedSources() const { return 0; }

std::vector<Individual *> SimpleVariationSource::perform(std::vector<Individual *> &parents, Thread &thread) const {
    for (auto *p : parents) {
        dynamic_cast<SimpleIndividual *>(p)->setLabel("bred");
    }
    return parents;
}