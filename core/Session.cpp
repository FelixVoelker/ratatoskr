#include "Session.h"
#include "evaluation/EvolutionaryNetwork.h"
#include "variation/BreedingOperator.h"

Session::Session(Problem &problem) : _problem(problem) {}

Session::~Session() {
    delete _individual;
    delete _builder;
    delete _network;
    delete _pipeline;
}

Problem & Session::problem() {
    return _problem;
}

EvolutionaryNetwork * Session::network() {
    return _network;
}

Builder * Session::builder() {
    return _builder;
}

Fitness * Session::fitness() {
    return _fitness;
}

Relevance * Session::relevance() {
    return _relevance;
}

FeatureMap * Session::featuremap() {
    return _featuremap;
}

Individual * Session::individual() {
    return _individual;
}

BreedingOperator * Session::pipeline() {
    return _pipeline;
}

unsigned int Session::epochs() {
    return _epochs;
}

unsigned int Session::episodes() {
    return _episodes;
}

unsigned int Session::generations() {
    return _generations;
}

unsigned int Session::evalthreads() {
    return _evalthreads;
}

unsigned int Session::varythreads() {
    return _varythreads;
}

float Session::learning_rate() {
    return _learning_rate;
}

float Session::discount_factor() {
    return _discount_factor;
}

void Session::epochs(unsigned int epochs) {
    this->_epochs = epochs;
}

void Session::episodes(unsigned int episodes) {
    this->_episodes = episodes;
}

void Session::generations(unsigned int generations) {
    this->_generations = generations;
}

void Session::evalthreads(unsigned int evalthreads) {
    this->_evalthreads = evalthreads;
}

void Session::varythreads(unsigned int varythreads) {
    this->_varythreads = varythreads;
}

void Session::learning_rate(float learning_rate) {
    this->_learning_rate = learning_rate;
}

void Session::discount_factor(float discount_factor) {
    this->_discount_factor = discount_factor;
}