#include "Session.h"

core::Session::Session(const Problem &problem) : problem(problem), configuration(new Configuration(problem.getConfiguration())) {}

core::Session::Session(const Problem &problem, core::Configuration *config) : problem(problem), configuration(new Configuration(*config)) {}

core::Session::~Session() {
    delete configuration;
}

EvolutionarySystem * core::Session::build(Builder *builder,
                                   EvolutionaryNetwork *network,
                                   BreedingOperator *variation_tree) {
    return new EvolutionarySystem(*configuration, builder, problem.getEval(), network, variation_tree);
}

core::Configuration & core::Session::getConfiguration() {
    return *configuration;
}

