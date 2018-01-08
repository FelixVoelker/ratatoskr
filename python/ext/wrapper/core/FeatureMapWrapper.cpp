#include "FeatureMapWrapper.h"

FeatureMapWrapper::FeatureMapWrapper(Configuration &configuration) : FeatureMap(configuration) {}

FeatureMap* FeatureMapWrapper::clone() const {
    return this->get_override("clone")();
}