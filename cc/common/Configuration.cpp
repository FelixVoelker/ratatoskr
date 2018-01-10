#include "Configuration.h"

common::Configuration::ProblemConfiguration::ProblemConfiguration()
        : core::Configuration::ProblemConfiguration::ProblemConfiguration() {}

common::Configuration::ProblemConfiguration::ProblemConfiguration(const ProblemConfiguration &obj)
        : core::Configuration::ProblemConfiguration::ProblemConfiguration(obj) {
    this->genes = obj.genes;
}

common::Configuration::CrossoverConfiguration::CrossoverConfiguration(const CrossoverConfiguration &obj) {
    this->xover_rate = obj.xover_rate;
}

common::Configuration::MutationConfiguration::MutationConfiguration(const MutationConfiguration &obj) {
    this->mutation_rate = mutation_rate;
}

common::Configuration::Configuration(ProblemConfiguration &problem)
        : core::Configuration::Configuration(problem) {}

common::Configuration::CrossoverConfiguration & common::Configuration::getCrossoverConfiguration() {
    return crossover;
}

common::Configuration::MutationConfiguration & common::Configuration::getMutationConfiguration() {
    return mutation;
}