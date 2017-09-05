#include "Individual.h"

Individual::Individual(Individual &obj) : Prototype(obj) {
    relevance = dynamic_cast<Relevance *>(obj.getRelevance().clone());
    featuremap = dynamic_cast<FeatureMap *>(obj.getFeaturemap().clone());
}

Individual::Individual(Session &session) : Prototype(session) {
    relevance = session.relevance();
    featuremap = session.featuremap();
}

Individual::~Individual() {
    delete relevance;
    delete featuremap;
}

Relevance & Individual::getRelevance() {
    return *relevance;
}

FeatureMap & Individual::getFeaturemap() {
    return *featuremap;
}

bool Individual::evaluated() {
    return _evaluated;
}

void Individual::evaluated(bool evaluated) {
    this->_evaluated = evaluated;
}