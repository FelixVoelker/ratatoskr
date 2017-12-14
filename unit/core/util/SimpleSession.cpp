#include "SimpleSession.h"
#include "../../../core/representation/Fitness.h"
#include "SimpleFeatureMap.h"
#include "SimpleIndividual.h"

SimpleSession::SimpleSession(Problem &problem) : Session(problem) {
//    builder = new TestBuilder(*this);
    cost = new Cost(*this);
    featuremap = new SimpleFeatureMap(*this);
    fitness = new Fitness(*this);
    individual = new SimpleIndividual(*this);
//    vector<VariationSource *> sources(1);
//    sources.at(0) = new FitnessProportionateSelection(*this);
//    pipeline = new TestBreedingOperator(*this);
//    pipeline->connect(sources);
}

//void SimpleSession::setBuilder(Builder &builder_prototype) {}
void SimpleSession::setCost(Cost &cost_prototype) {}
void SimpleSession::setFeaturemap(FeatureMap &featuremap_prototype) {}
void SimpleSession::setFitness(Fitness &fitness_prototype) {}
void SimpleSession::setIndividual(Individual &individual_prototype) {}
//void SimpleSession::setPipeline(BreedingOperator &pipeline_prototype) {}