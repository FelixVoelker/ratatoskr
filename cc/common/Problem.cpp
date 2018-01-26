#include "Problem.h"

common::Problem::Problem(EvaluationFunction &eval, unsigned int popsize, unsigned int genes)
        : core::Problem::Problem(eval, new common::Configuration::ProblemConfiguration(), popsize)
{
    dynamic_cast<common::Configuration::ProblemConfiguration *>(configuration)->genes = genes;
}

common::Problem::Problem(const Problem &obj) : core::Problem(obj) {
    auto * config = dynamic_cast<common::Configuration::ProblemConfiguration *>(obj.configuration);
    this->configuration = new common::Configuration::ProblemConfiguration(*config);
}
