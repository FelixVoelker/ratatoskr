#include <typeinfo>
#include <iostream>
#include "NDGASession.h"
#include "../../../core/evaluation/EvolutionaryNetwork.h"
#include "FeatureVector.h"
#include "BitVectorIndividual.h"
#include "RandomBitVectorBuilder.h"
#include "BitVectorMutation.h"
#include "BitVectorCrossover.h"
#include "../common/FitnessProportionateSelection.h"

NDGASession::NDGASession(const NDGAProblem &problem) : Session(problem) {
    _fitness = new Fitness(*this);
    _relevance = new Relevance(*this);
    _featuremap = new FeatureVector(*this);
    _individual = new BitVectorIndividual(*this);
    _builder = new RandomBitVectorBuilder(*this);
    _network = new EvolutionaryNetwork(*this);

    vector<VariationSource *> selectors(2);
    selectors.at(0) = new FitnessProportionateSelection(*this);
    selectors.at(1) = new FitnessProportionateSelection(*this);
    vector<VariationSource *> crossover(1);
    crossover.at(0) = new BitVectorCrossover(*this);
    crossover.at(0)->connect(selectors);
    _pipeline = new BitVectorMutation(*this);
    _pipeline->connect(crossover);
}

void NDGASession::network(EvolutionaryNetwork &network) {
    _network = &network;
}

void NDGASession::builder(Builder &builder) {
    _builder = dynamic_cast<RandomBitVectorBuilder *>(&builder);
}

void NDGASession::fitness(Fitness &fitness_prototype) {
    _fitness = &fitness_prototype;
}

void NDGASession::relevance(Relevance &relevance_prototype) {
    _relevance = &relevance_prototype;
}

void NDGASession::featuremap(FeatureMap &featuremap_prototype) {
    _featuremap = dynamic_cast<FeatureVector *>(&featuremap_prototype);
}

void NDGASession::individual(Individual &individual_prototype) {
    _individual = dynamic_cast<BitVectorIndividual *>(&individual_prototype);
}

void NDGASession::pipeline(BreedingOperator &pipeline_prototype) {
    _pipeline = &pipeline_prototype;
}