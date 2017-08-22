#include "Session.h"

Session::Session(Problem &problem) : _problem(problem) {}

Session::~Session() {
    delete _builder;
    delete _fitness;
    delete _featuremap;
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
    return &_fitness;
}

FeatureMap ** Session::featuremap() {
    return &_featuremap;
}

Individual ** Session::individual() {
    return &_individual;
}

BreedingOperator ** Session::pipeline() {
    return &_pipeline;
}