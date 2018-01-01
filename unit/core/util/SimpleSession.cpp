#include "SimpleSession.h"
#include "../../../core/representation/Fitness.h"
#include "SimpleFeatureMap.h"
#include "SimpleIndividual.h"
#include "SimpleBuilder.h"

SimpleSession::SimpleSession(Problem &problem) : Session(problem) {
    cost = new Cost(*this);
    featuremap = new SimpleFeatureMap(*this);
    fitness = new Fitness(*this);
    individual = new SimpleIndividual(*this);
    builder = new SimpleBuilder(*this);
//    vector<VariationSource *> sources(1);
//    sources.at(0) = new FitnessProportionateSelection(*this);
//    pipeline = new SimpleBreedingOperator(*this);
//    pipeline->setup(sources);
}

void SimpleSession::setBuilder(Builder &builder_prototype) {}
void SimpleSession::setCost(Cost &cost_prototype) {}
void SimpleSession::setFeaturemap(FeatureMap &featuremap_prototype) {}
void SimpleSession::setFitness(Fitness &fitness_prototype) {}
void SimpleSession::setIndividual(Individual &individual_prototype) {}
//void SimpleSession::setPipeline(BreedingOperator &pipeline_prototype) {}