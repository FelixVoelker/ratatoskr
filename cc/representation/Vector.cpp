#include "Vector.h"

Vector::Chromosome::Chromosome(unsigned int genes) : Genotype() {
    this->chromosome = std::vector<float>(genes);
}

std::string Vector::Chromosome::toString() {
    std::string str = "(";
    for (int k = 0; k < chromosome.size() - 1; k++) {
        str += std::to_string(chromosome.at(k));
        str +=  ", ";
    }
    str += std::to_string(chromosome.at(chromosome.size() - 1));
    str += ")";
    return str;
}

std::vector<float> & Vector::Chromosome::getChromosome() {
    return chromosome;
}

Genotype * Vector::Chromosome::clone() const {
    return new Chromosome(*this);
}

Vector::Chromosome::Chromosome(const Chromosome &obj) {
    this->chromosome = obj.chromosome;
}