#include "Session.h"

core::Session::Session(Problem &problem) : problem(problem), configuration(new Configuration(problem.getConfiguration())) {}

core::Session::Session(Problem &problem, Configuration *config) : problem(problem), configuration(new Configuration(*config)) {}

core::Session::~Session() {
    delete configuration;
}

EvolutionarySystem* core::Session::build(Builder *builder,
                                   EvolutionaryNetwork *network,
                                   BreedingOperator *variation_tree) {
    return new EvolutionarySystem(*configuration, builder, problem.getEval(), network, variation_tree);
}

Configuration & core::Session::getConfiguration() {
    return *configuration;
}

