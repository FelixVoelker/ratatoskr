#include <iostream>
#include "VectorIndividual.h"

VectorIndividual::VectorIndividual(const common::Configuration &configuration,
                                   Cost *cost,
                                   FeatureVector *featurevector,
                                   Fitness *fitness)
        : Individual(configuration, cost, featurevector, fitness)
{
    auto problem = dynamic_cast<const common::Configuration::ProblemConfiguration &>(configuration.getProblemConfiguration());
    unsigned int genes = problem.genes;
    this->chromosome = std::vector<float>(genes);
}

std::string VectorIndividual::toString() {
    bool is_bitstring = true;
    for (auto c : chromosome) {
        if (c != 0 && c != 1) {
            is_bitstring = false;
            break;
        }
    }

    std::string str;
    if (!is_bitstring) {
        str += "(";
    }
    for (int k = 0; k < chromosome.size() - 1; k++) {
        if (is_bitstring) {
            str += std::to_string(static_cast<unsigned int>(chromosome.at(k)));
        } else {
            str += std::to_string(chromosome.at(k));
            size_t last_non_zero = str.find_last_not_of('0');
            if (str.at(last_non_zero) == '.') {
                str.erase(last_non_zero + 2, std::string::npos);
            } else {
                str.erase(last_non_zero + 1, std::string::npos);
            }
            str +=  ", ";
        }

    }
    if (is_bitstring) {
        str += std::to_string(static_cast<unsigned int>(chromosome.at(chromosome.size() - 1)));
    } else {
        str += std::to_string(chromosome.at(chromosome.size() - 1));
        size_t last_non_zero = str.find_last_not_of('0');
        if (str.at(last_non_zero) == '.') {
            str.erase(last_non_zero + 2, std::string::npos);
        } else {
            str.erase(last_non_zero + 1, std::string::npos);
        }
        str += ")";
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