#include "Problem.h"

common::Problem::Problem(std::function<void(Individual &, Thread &)> eval, unsigned int popsize, unsigned int genes)
        : core::Problem(eval, popsize) {
    configuration.genes = genes;
}

common::Problem::Problem(const Problem &obj) : core::Problem(obj) {
    this->configuration = common::Configuration::ProblemConfiguration(obj.configuration);
}
