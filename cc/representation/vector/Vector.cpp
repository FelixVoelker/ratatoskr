#include "Vector.h"

Vector::Vector(unsigned int genes) : Genotype() {
    this->chromosome = std::vector<float>(genes);
}

std::string Vector::toString() {
    std::string str = "(";
    for (int k = 0; k < chromosome.size() - 1; k++) {
        str += std::to_string(chromosome.at(k));
        str +=  ", ";
    }
    str += std::to_string(chromosome.at(chromosome.size() - 1));
    str += ")";
    return str;
}

Genotype * Vector::clone() const {
    return new Vector(*this);
}

std::vector<float> & Vector::getChromosome() {
    return chromosome;
}

Vector::Vector(const Vector &obj) {
    this->chromosome = obj.chromosome;
}