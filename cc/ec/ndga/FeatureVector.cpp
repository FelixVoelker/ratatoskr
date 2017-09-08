#include "FeatureVector.h"

FeatureVector::FeatureVector(const NDGASession &session) : FeatureMap(session) {}

vector<float> FeatureVector::compute(vector<unsigned int> &chromosome) const {
    vector<float> features(chromosome.size());
    for (int k = 0; k < chromosome.size(); k++) {
        features.at(k) = chromosome.at(k);
    }
    return features;
}

FeatureVector * FeatureVector::clone() const {
    return new FeatureVector(*this);
}