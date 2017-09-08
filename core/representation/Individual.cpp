#include "Individual.h"

Individual::Individual(const Individual &obj) : Prototype(obj) {
    relevance = dynamic_cast<Relevance *>(obj.relevance->clone());
    featuremap = dynamic_cast<FeatureMap *>(obj.featuremap->clone());
}

Individual::Individual(const Session &session) : Prototype(session) {
    relevance = session.relevance();
    featuremap = session.featuremap();
}

Individual::~Individual() {
    delete relevance;
    delete featuremap;
}

Relevance & Individual::getRelevance() const {
    return *relevance;
}

FeatureMap & Individual::getFeaturemap() const {
    return *featuremap;
}

bool Individual::evaluated() const {
    return _evaluated;
}

void Individual::evaluated(const bool evaluated) {
    this->_evaluated = evaluated;
}