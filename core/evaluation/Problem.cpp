#include "Problem.h"

Problem::Problem(std::function<void(Individual &, Thread &)> eval, const unsigned int popsize) {
    this->eval = eval;
    this->configuration.popsize = popsize;
}

Problem::Problem(const Problem &obj) {
    this->eval = obj.eval;
    this->configuration = Configuration::ProblemConfiguration(obj.configuration);
}

std::function<void(Individual &, Thread &)> & Problem::getEval() {
    return eval;
}

Configuration::ProblemConfiguration & Problem::getConfiguration() {
    return configuration;
}

void Problem::setEval(std::function<void(Individual &, Thread &)> eval) {
    this->eval = eval;
}