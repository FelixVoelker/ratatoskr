#include <typeinfo>
#include <iostream>
#include "NDGASession.h"
#include "../../core/experience/EvolutionaryNetwork.h"
#include "../common/FeatureVector.h"
#include "../common/VectorIndividual.h"
#include "RandomBitVectorBuilder.h"
#include "BitVectorMutation.h"
#include "BitVectorCrossover.h"
#include "../common/FitnessProportionateSelection.h"

NDGASession::NDGASession(const NDGAProblem &problem) : Configuration(problem) {
    fitness = new Fitness(*this);
    cost = new Cost(*this);
    featuremap = new FeatureVector(*this);
    individual = new VectorIndividual(*this);
    builder = new RandomBitVectorBuilder(*this);
    network = new EvolutionaryNetwork(*this);

    vector<VariationSource *> selectors(2);
    selectors.at(0) = new FitnessProportionateSelection(*this);
    selectors.at(1) = new FitnessProportionateSelection(*this);
    vector<VariationSource *> crossover(1);
    crossover.at(0) = new BitVectorCrossover(*this);
    crossover.at(0)->setup(selectors);
    pipeline = new BitVectorMutation(*this);
    pipeline->connect(crossover);
}

void NDGASession::setNetwork(EvolutionaryNetwork &network) {
    network = &network;
}

void NDGASession::setBuilder(Builder &builder) {
    builder = dynamic_cast<RandomBitVectorBuilder *>(&builder);
}

void NDGASession::setFitness(Fitness &fitness_prototype) {
    fitness = &fitness_prototype;
}

void NDGASession::setCost(Cost &relevance_prototype) {
    cost = &relevance_prototype;
}

void NDGASession::setFeaturemap(FeatureMap &featuremap_prototype) {
    featuremap = dynamic_cast<FeatureVector *>(&featuremap_prototype);
}

void NDGASession::setIndividual(Individual &individual_prototype) {
    individual = dynamic_cast<VectorIndividual *>(&individual_prototype);
}

void NDGASession::setPipeline(BreedingOperator &pipeline_prototype) {
    pipeline = &pipeline_prototype;
}