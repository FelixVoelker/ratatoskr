#include "FeatureVector.h"
#include "BitVectorIndividual.h"

FeatureVector::FeatureVector(Session &session) : FeatureMap(session) {}

vector<float> FeatureVector::compute(vector<unsigned int> &chromosome) {
    vector<float> features(chromosome.size());
    for (int k = 0; k < chromosome.size(); k++) {
        features.at(k) = chromosome.at(k);
    }
    return features;
}

FeatureVector * FeatureVector::clone() {
    return new FeatureVector(*this);
}