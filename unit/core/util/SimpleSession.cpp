#include "SimpleSession.h"
#include "../../../core/representation/Fitness.h"
#include "SimpleFeatureMap.h"
#include "SimpleIndividual.h"
#include "SimpleBuilder.h"
#include "SimpleSelectionOperator.h"
#include "SimpleBreedingOperator.h"
#include "SimpleEvolutionaryNetwork.h"

SimpleSession::SimpleSession(Problem &problem) : Session(problem) {
    cost = new Cost(*this);
    featuremap = new SimpleFeatureMap(*this);
    fitness = new Fitness(*this);
    individual = new SimpleIndividual(*this);
    builder = new SimpleBuilder(*this);
    auto *so = new SimpleSelectionOperator(*this);
    so->setup(*new std::vector<VariationSource *>(0));
    variation_tree = new SimpleBreedingOperator(*this);
    variation_tree->setup(*new std::vector<VariationSource *> = { so });
    network = new SimpleEvolutionaryNetwork(*this);
}

void SimpleSession::setBuilder(Builder &builder_prototype) {}
void SimpleSession::setCost(Cost &cost_prototype) {}
void SimpleSession::setFeaturemap(FeatureMap &featuremap_prototype) {}
void SimpleSession::setFitness(Fitness &fitness_prototype) {}
void SimpleSession::setIndividual(Individual &individual_prototype) {}
//void SimpleSession::setPipeline(BreedingOperator &pipeline_prototype) {}