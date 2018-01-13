#include "IndividualWrapper.h"

IndividualWrapper::IndividualWrapper(const core::Configuration &configuration,
                                     Cost *cost,
                                     FeatureMap *featuremap,
                                     Fitness *fitness)
        : Individual(configuration, cost, featuremap, fitness)
{
}

std::string IndividualWrapper::toString() {
    return this->get_override("toString")();
}

Individual* IndividualWrapper::clone() const {
    return this->get_override("clone")();
}