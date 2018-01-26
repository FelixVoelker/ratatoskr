#include "Individual.h"

Individual::Individual(const core::Configuration &configuration, FeatureMap &featuremap, Relevance &relevance)
        : Prototype(configuration)
{
    this->featuremap = featuremap.clone();
    this->relevance = relevance.clone();
}

Individual::~Individual() {
    delete featuremap;
    delete relevance;
}

FeatureMap & Individual::getFeaturemap() const {
    return *featuremap;
}

Relevance & Individual::getRelevance() const {
    return *relevance;
}

bool Individual::isEvaluated() const {
    return evaluated;
}

void Individual::setEvaluated(const bool evaluated) {
    this->evaluated = evaluated;
}

Individual::Individual(const Individual &obj) : Prototype(obj) {
    featuremap = obj.featuremap->clone();
    relevance = obj.relevance->clone();
}