#include "Problem.h"

core::Problem::Problem(EvaluationFunction &eval, const unsigned int popsize) {
    this->eval = eval.clone();
    configuration = new Configuration::ProblemConfiguration();
    configuration->popsize = popsize;
}

core::Problem::Problem(const Problem &obj) {
    this->eval = obj.eval->clone();
    this->configuration = new Configuration::ProblemConfiguration(*obj.configuration);
}

core::Problem::~Problem() {
    delete eval;
    delete configuration;
}

const EvaluationFunction & core::Problem::getEval() const {
    return *eval;
}

core::Configuration::ProblemConfiguration & core::Problem::getConfiguration() {
    return *configuration;
}

const core::Configuration::ProblemConfiguration & core::Problem::getConfiguration() const {
    return *configuration;
}

void core::Problem::setEval(EvaluationFunction &eval) {
    delete this->eval;
    this->eval = eval.clone();
}

core::Problem::Problem(EvaluationFunction &eval,
                 Configuration::ProblemConfiguration *configuration,
                 unsigned int popsize)
{
    this->eval = eval.clone();
    this->configuration = configuration;
    this->configuration->popsize = popsize;
}