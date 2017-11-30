#include "SimpleSession.h"
#include "../../../core/representation/Fitness.h"
//#include "TestBuilder.h"
//#include "TestFeatureMap.h"
//#include "TestIndividual.h"
//#include "../../../cc/ec/common/FitnessProportionateSelection.h"
//#include "TestBreedingOperator.h"

SimpleSession::SimpleSession(Problem &problem) : Session(problem) {
//    builder = new TestBuilder(*this);
    fitness = new Fitness(*this);
//    featuremap = new TestFeatureMap(*this);
//    individual = new TestIndividual(*this);
//    vector<VariationSource *> sources(1);
//    sources.at(0) = new FitnessProportionateSelection(*this);
//    pipeline = new TestBreedingOperator(*this);
//    pipeline->connect(sources);
}

//void SimpleSession::setBuilder(Builder &builder_prototype) {}
void SimpleSession::setFitness(Fitness &fitness_prototype) {}
//void SimpleSession::setFeaturemap(FeatureMap &featuremap_prototype) {}
//void SimpleSession::setIndividual(Individual &individual_prototype) {}
//void SimpleSession::setPipeline(BreedingOperator &pipeline_prototype) {}