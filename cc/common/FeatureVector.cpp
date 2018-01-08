#include "FeatureVector.h"
#include "Configuration.h"

FeatureVector::FeatureVector(common::Configuration &configuration) : FeatureMap(configuration) {}

std::vector<float> & FeatureVector::compute(std::vector<float> &chromosome) const {
    return chromosome;
}

FeatureVector * FeatureVector::clone() const {
    return new FeatureVector(*this);
}