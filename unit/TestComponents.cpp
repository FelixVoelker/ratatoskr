#include "TestComponents.h"
#include "../cc/toolbox/ec/common/RawFitness.h"
#include "../cc/toolbox/ec/common/FitnessProportionateSelection.h"

TestProblem::TestProblem() : Problem(4) {}

void TestProblem::evaluate(Individual &individual) {
    dynamic_cast<RawFitness &>(individual.getFitness()).setFitness(1);
}

TestSession::TestSession(Problem &problem) : Session(problem) {
    _builder = new TestBuilder(*this);
    _fitness = new RawFitness(*this);
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

TestBuilder::TestBuilder(Session &session) : Builder(session) {}

void TestBuilder::initialize(Individual &ind) {}

TestIndividual::TestIndividual(Session &session) : Individual(session) {}

TestIndividual * TestIndividual::clone() {
    return new TestIndividual(*this);
}

string TestIndividual::toString() { return ""; }

TestFeatureMap::TestFeatureMap(Session &session) : FeatureMap(session) {}

TestFeatureMap * TestFeatureMap::clone() {
    return new TestFeatureMap(*this);
}

unsigned long TestSource::expectedSources() { return 1; }

vector<Individual *> TestSource::perform(Population &pop, vector<Individual *> parents, Randomizer &random) {
    return vector<Individual *>();
}

TestSource::TestSource(Session &session) : VariationSource(session) {}

unsigned long TestBreedingOperator::expectedSources() {
    return 1;
}

vector<Individual *> TestBreedingOperator::breed(vector<Individual *> parents, Randomizer &random) {
    return vector<Individual *>();
}

TestBreedingOperator::TestBreedingOperator(Session &session) : BreedingOperator(session) {}
