#include "IndividualWrapper.h"

IndividualWrapper::IndividualWrapper(const core::Configuration &configuration, FeatureMap &featuremap, Relevance &relevance)
        : Individual(configuration, featuremap, relevance)
{
}

std::string IndividualWrapper::toString() {
    return this->get_override("toString")();
}

Individual* IndividualWrapper::clone() const {
    return this->get_override("clone")();
}