#include "SessionWrapper.h"

SessionWrapper::SessionWrapper(boost::shared_ptr<Problem> problem) : Session(*problem) {}

//void SessionWrapper::setNetwork(EvolutionaryNetwork &network_prototype) {
//    this->get_override("getNetwork")(network_prototype);
//}

void SessionWrapper::setBuilder(Builder &builder_prototype) {
    this->get_override("getBuilder")(builder_prototype);
}

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
//    this->get_override("getVariationTree")(pipeline_prototype);
//}

void SessionWrapper::pyBuilder(boost::shared_ptr<Builder> builder_prototype) {
    setBuilder(*builder_prototype);
}

void SessionWrapper::pyCost(boost::shared_ptr<Cost> cost_prototype) {
    setCost(*cost_prototype);
}

void SessionWrapper::pyFeaturemap(boost::shared_ptr<FeatureMap> featuremap_prototype) {
    setFeaturemap(*featuremap_prototype);
}

void SessionWrapper::pyFitness(boost::shared_ptr<Fitness> fitness_prototype) {
    setFitness(*fitness_prototype);
}

void SessionWrapper::pyIndividual(boost::shared_ptr<Individual> individual_prototype) {
    setIndividual(*individual_prototype);
}