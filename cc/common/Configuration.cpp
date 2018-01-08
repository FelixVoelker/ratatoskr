#include "Configuration.h"

common::Configuration::ProblemConfiguration::ProblemConfiguration()
        : core::Configuration::ProblemConfiguration::ProblemConfiguration() {}

common::Configuration::ProblemConfiguration::ProblemConfiguration(const ProblemConfiguration &obj)
        : core::Configuration::ProblemConfiguration::ProblemConfiguration(obj) {
    this->genes = obj.genes;
}

common::Configuration::Configuration(ProblemConfiguration &problem)
        : core::Configuration::Configuration(problem) {}