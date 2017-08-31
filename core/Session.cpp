#include "Session.h"
#include "initialization/Builder.h"
#include "variation/BreedingOperator.h"

Session::Session(Problem &problem) : _problem(problem) {}

Session::~Session() {
    delete _builder;
    delete _individual;
    delete _pipeline;
}

Problem & Session::problem() {
    return _problem;
}

Builder ** Session::builder() {
    return &_builder;
}

Fitness ** Session::fitness() {
    auto fitness = new Fitness*;
    *fitness = _fitness;
    return fitness;
}

FeatureMap ** Session::featuremap() {
    auto featuremap = new FeatureMap*;
    *featuremap = _featuremap;
    return featuremap;
}

Individual ** Session::individual() {
    return &_individual;
}

BreedingOperator ** Session::pipeline() {
    return &_pipeline;
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

void Session::generations(unsigned int generations) {
    this->_generations = generations;
}

void Session::evalthreads(unsigned int evalthreads) {
    this->_evalthreads = evalthreads;
}

void Session::varythreads(unsigned int varythreads) {
    this->_varythreads = varythreads;
}