#include "Session.h"
#include "evaluation/EvolutionaryNetwork.h"
#include "variation/BreedingOperator.h"

Session::Session(const Problem &problem) : _problem(problem) {}

Session::~Session() {
    delete _individual;
    delete _builder;
    delete _network;
    delete _pipeline;
}

const Problem & Session::problem() const {
    return _problem;
}

EvolutionaryNetwork * Session::network() const {
    return _network;
}

Builder * Session::builder() const {
    return _builder;
}

Fitness * Session::fitness() const {
    return _fitness;
}

Relevance * Session::relevance() const {
    return _relevance;
}

FeatureMap * Session::featuremap() const {
    return _featuremap;
}

Individual * Session::individual() const {
    return _individual;
}

BreedingOperator * Session::pipeline() const {
    return _pipeline;
}

unsigned int Session::epochs() const {
    return _epochs;
}

unsigned int Session::episodes() const {
    return _episodes;
}

unsigned int Session::generations() const {
    return _generations;
}

bool Session::complete() const {
    return _complete;
}

unsigned int Session::evalthreads() const {
    return _evalthreads;
}

unsigned int Session::varythreads() const {
    return _varythreads;
}

float Session::learning_rate() const {
    return _learning_rate;
}

float Session::discount_factor() const {
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

void Session::complete(bool complete) {
    this->_complete = complete;
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