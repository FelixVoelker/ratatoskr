#include "SessionWrapper.h"

SessionWrapper::SessionWrapper(boost::shared_ptr<Problem> problem) : Session(*problem) {}

//void SessionWrapper::setNetwork(EvolutionaryNetwork &network_prototype) {
//    this->get_override("getNetwork")(network_prototype);
//}
//
//void SessionWrapper::setBuilder(Builder &builder_prototype) {
//    this->get_override("getBuilder")(builder_prototype);
//}

void SessionWrapper::setCost(Cost &relevance_prototype) {
    this->get_override("setCost")(relevance_prototype);
}

void SessionWrapper::setFeaturemap(FeatureMap &featuremap_prototype) {
    this->get_override("getFeaturemap")(featuremap_prototype);
}

void SessionWrapper::setFitness(Fitness &fitness_prototype) {
    this->get_override("setFitness")(fitness_prototype);
}

void SessionWrapper::setIndividual(Individual &individual_prototype) {
    this->get_override("getIndividual")(individual_prototype);
}

//void SessionWrapper::setPipeline(BreedingOperator &pipeline_prototype) {
//    this->get_override("getPipeline")(pipeline_prototype);
//}

void SessionWrapper::pyFitness(boost::shared_ptr<Fitness> fitness_prototype) {
    setFitness(*fitness_prototype);
}