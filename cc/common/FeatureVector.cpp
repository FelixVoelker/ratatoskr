#include "FeatureVector.h"

FeatureVector::FeatureVector(const common::Configuration &configuration) : FeatureMap(configuration) {}

std::vector<float> & FeatureVector::compute(std::vector<float> &chromosome) const {
    return chromosome;
}

FeatureVector * FeatureVector::clone() const {
    return new FeatureVector(*this);
}