#include "Individual.h"

Individual::Individual(Individual &obj) : Prototype(obj) {
    fitness = new Fitness*;
    *fitness = dynamic_cast<Fitness *>(obj.getFitness().clone());
    featuremap = new FeatureMap*;
    *featuremap = dynamic_cast<FeatureMap *>(obj.getFeaturemap().clone());
}

Individual::Individual(Session &session) : Prototype(session) {
    fitness = session.fitness();
    featuremap = session.featuremap();
}

Individual::~Individual() {
    delete *fitness;
    delete fitness;
    delete *featuremap;
    delete featuremap;
}

Fitness & Individual::getFitness() {
    return **fitness;
}

FeatureMap & Individual::getFeaturemap() {
    return **featuremap;
}

bool Individual::evaluated() {
    return _evaluated;
}

void Individual::evaluated(bool evaluated) {
    this->_evaluated = evaluated;
}