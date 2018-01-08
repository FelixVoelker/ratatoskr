#include "Problem.h"

Problem::Problem(std::function<void(Individual &, Thread &)> eval, const unsigned int popsize) {
    this->eval = eval;
    configuration = new Configuration::ProblemConfiguration();
    configuration->popsize = popsize;
}

Problem::Problem(const Problem &obj) {
    this->eval = obj.eval;
    this->configuration = new Configuration::ProblemConfiguration(*obj.configuration);
}

Problem::~Problem() {
    delete configuration;
}

std::function<void(Individual &, Thread &)> & Problem::getEval() {
    return eval;
}

Configuration::ProblemConfiguration & Problem::getConfiguration() {
    return *configuration;
}

void Problem::setEval(std::function<void(Individual &, Thread &)> eval) {
    this->eval = eval;
}

Problem::Problem(std::function<void(Individual &, Thread &)> eval,
                 Configuration::ProblemConfiguration *configuration,
                 unsigned int popsize)
{
    this->eval = eval;
    this->configuration = configuration;
    this->configuration->popsize = popsize;
}