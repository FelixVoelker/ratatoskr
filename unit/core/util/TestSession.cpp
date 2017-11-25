#include "TestSession.h"
#include "TestBuilder.h"
#include "TestFeatureMap.h"
#include "TestIndividual.h"
#include "../../../cc/ec/common/FitnessProportionateSelection.h"
#include "TestBreedingOperator.h"

TestSession::TestSession(Problem &problem) : Session(problem) {
    _builder = new TestBuilder(*this);
    _fitness = new Fitness(*this);
    _featuremap = new TestFeatureMap(*this);
    _individual = new TestIndividual(*this);
    vector<VariationSource *> sources(1);
    sources.at(0) = new FitnessProportionateSelection(*this);
    _pipeline = new TestBreedingOperator(*this);
    _pipeline->connect(sources);
}

void TestSession::builder(Builder &builder_prototype) {}
void TestSession::fitness(Fitness &fitness_prototype) {}
void TestSession::featuremap(FeatureMap &featuremap_prototype) {}
void TestSession::individual(Individual &individual_prototype) {}
void TestSession::pipeline(BreedingOperator &pipeline_prototype) {}