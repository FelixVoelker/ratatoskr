#include <iostream>
#include "VectorIndividual.h"

VectorIndividual::VectorIndividual(common::Configuration &configuration,
                                   Cost *cost,
                                   FeatureMap *featuremap,
                                   Fitness *fitness)
        : Individual(configuration, cost, featuremap, fitness)
{
    auto problem = dynamic_cast<common::Configuration::ProblemConfiguration &>(configuration.getProblemConfiguration());
    unsigned int genes = problem.genes;
    this->chromosome = std::vector<float>(genes);
}

std::string VectorIndividual::toString() {
    std::string str;
    for (float k : chromosome) {
        str += std::to_string(k);
    }
    return str;
}

VectorIndividual * VectorIndividual::clone() const {
    return new VectorIndividual(*this);
}

std::vector<float> & VectorIndividual::getChromosome() {
    return chromosome;
}

VectorIndividual::VectorIndividual(const VectorIndividual &obj) : Individual(obj) {
    this->chromosome = obj.chromosome;
}