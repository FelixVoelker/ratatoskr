#include "Session.h"

Session::Session(Problem &problem) : problem(problem), configuration(new Configuration(problem.getConfiguration())) {}

Session::Session(Problem &problem, Configuration *config) : problem(problem), configuration(new Configuration(*config)) {}

Session::~Session() {
    delete configuration;
}

EvolutionarySystem* Session::build(Builder *builder,
                                   EvolutionaryNetwork *network,
                                   BreedingOperator *variation_tree) {
    return new EvolutionarySystem(*configuration, builder, problem.getEval(), network, variation_tree);
}

Configuration & Session::getConfiguration() {
    return *configuration;
}

