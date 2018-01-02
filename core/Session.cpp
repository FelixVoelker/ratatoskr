#include "Session.h"
#include "initialization/Builder.h"

Session::Session(Problem &problem) : problem(problem) {}

Session::~Session() {
    delete individual;
    delete builder;
//    delete network;
//    delete pipeline;
}

Problem & Session::getProblem() const {
    return problem;
}

//EvolutionaryNetwork * Session::getNetwork() const {
//    return network;
//}

Builder * Session::getBuilder() const {
    return builder;
}

Fitness * Session::getFitness() const {
    return fitness;
}

Cost * Session::getCost() const {
    return cost;
}

FeatureMap * Session::getFeaturemap() const {
    return featuremap;
}

Individual * Session::getIndividual() const {
    return individual;
}

BreedingOperator * Session::getVariationTree() const {
    return variation_tree;
}

unsigned int Session::getEpochs() const {
    return epochs;
}

unsigned int Session::getEpisodes() const {
    return episodes;
}

unsigned int Session::getGenerations() const {
    return generations;
}

bool Session::isComplete() const {
    return complete;
}

unsigned int Session::getInitthreads() const {
    return initthreads;
}

unsigned int Session::getEvalthreads() const {
    return evalthreads;
}

unsigned int Session::getVarythreads() const {
    return varythreads;
}

float Session::getLearningRate() const {
    return learning_rate;
}

float Session::getDiscountFactor() const {
    return discount_factor;
}

void Session::setEpochs(unsigned int epochs) {
    this->epochs = epochs;
}

void Session::setEpisodes(unsigned int episodes) {
    this->episodes = episodes;
}

void Session::setGenerations(unsigned int generations) {
    this->generations = generations;
}

void Session::setComplete(bool complete) {
    this->complete = complete;
}

void Session::setInitthreads(unsigned int initthreads) {
    this->initthreads = initthreads;
}

void Session::setEvalthreads(unsigned int evalthreads) {
    this->evalthreads = evalthreads;
}

void Session::setVarythreads(unsigned int varythreads) {
    this->varythreads = varythreads;
}

void Session::setLearningRate(float learning_rate) {
    this->learning_rate = learning_rate;
}

void Session::setDiscountFactor(float discount_factor) {
    this->discount_factor = discount_factor;
}