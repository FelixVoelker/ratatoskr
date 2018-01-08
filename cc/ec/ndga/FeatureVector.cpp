#include "FeatureVector.h"

FeatureVector::FeatureVector(const NDGASession &session) : FeatureMap(session) {}

std::vector<float> & FeatureVector::compute(std::vector<float> &chromosome) const {
    return chromosome;
}

FeatureVector * FeatureVector::clone() const {
    return new FeatureVector(*this);
}