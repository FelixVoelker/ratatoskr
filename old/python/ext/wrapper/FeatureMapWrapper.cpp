#include "FeatureMapWrapper.h"

FeatureMapWrapper::FeatureMapWrapper(const core::Configuration &configuration) : FeatureMap(configuration) {}

FeatureMap* FeatureMapWrapper::clone() const {
    return this->get_override("clone")();
}