#include "Problem.h"

core::Problem::Problem(std::function<void(Individual &, Thread &)> eval, const unsigned int popsize) {
    this->eval = eval;
    configuration = new Configuration::ProblemConfiguration();
    configuration->popsize = popsize;
}

core::Problem::Problem(const Problem &obj) {
    this->eval = obj.eval;
    this->configuration = new Configuration::ProblemConfiguration(*obj.configuration);
}

core::Problem::~Problem() {
    delete configuration;
}

const std::function<void(Individual &, Thread &)> & core::Problem::getEval() const {
    return eval;
}

core::Configuration::ProblemConfiguration & core::Problem::getConfiguration() {
    return *configuration;
}

const core::Configuration::ProblemConfiguration & core::Problem::getConfiguration() const {
    return *configuration;
}

void core::Problem::setEval(std::function<void(Individual &, Thread &)> eval) {
    this->eval = eval;
}

core::Problem::Problem(std::function<void(Individual &, Thread &)> eval,
                 Configuration::ProblemConfiguration *configuration,
                 unsigned int popsize)
{
    this->eval = eval;
    this->configuration = configuration;
    this->configuration->popsize = popsize;
}