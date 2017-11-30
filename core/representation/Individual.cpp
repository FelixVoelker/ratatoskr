#include "Individual.h"

Individual::Individual(const Individual &obj) : Prototype(obj) {
    relevance = obj.relevance->clone();
    featuremap = dynamic_cast<FeatureMap *>(obj.featuremap->clone());
}

Individual::Individual(const Session &session) : Prototype(session) {
    relevance = session.getCost();
    featuremap = session.getFeaturemap();
}

Individual::~Individual() {
    delete featuremap;
}

float Individual::relevance(float fraction) {
    return 1 / (1 + (1 - fraction) * fitness->getFitness() + fraction * cost->getApproximateCost());
}

Cost & Individual::getCost() const {
    return *cost;
}

FeatureMap& Individual::getFeaturemap() const {
    return *featuremap;
}

Fitness & Individual::getFitness() const {
    return *fitness;
}

bool Individual::isEvaluated() const {
    return evaluated;
}

void Individual::setEvaluated(const bool evaluated) {
    this->evaluated = evaluated;
}