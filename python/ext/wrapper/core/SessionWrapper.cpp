#include "SessionWrapper.h"

SessionWrapper::SessionWrapper(boost::shared_ptr<Problem> problem) : Session(*problem) {}

void SessionWrapper::network(EvolutionaryNetwork &network_prototype) {
    this->get_override("network")(network_prototype);
}

void SessionWrapper::builder(Builder &builder_prototype) {
    this->get_override("builder")(builder_prototype);
}

void SessionWrapper::fitness(Fitness &fitness_prototype) {
    this->get_override("fitness")(fitness_prototype);
}

void SessionWrapper::relevance(Relevance &relevance_prototype) {
    this->get_override("relevance")(relevance_prototype);
}

void SessionWrapper::featuremap(FeatureMap &featuremap_prototype) {
    this->get_override("featuremap")(featuremap_prototype);
}

void SessionWrapper::individual(Individual &individual_prototype) {
    this->get_override("individual")(individual_prototype);
}

void SessionWrapper::pipeline(BreedingOperator &pipeline_prototype) {
    this->get_override("pipeline")(pipeline_prototype);
}