#include "IntegerVector.h"

IntegerVector::IntegerVector(unsigned int genes) : Genotype() {
    this->chromosome = std::vector<int>(genes);
}

std::string IntegerVector::toString() {
    std::string str = "(";
    for (unsigned int k = 0; k < chromosome.size() - 1; k++) {
        str += std::to_string(chromosome.at(k));
        str += ", "
    }
    str += std::to_string(chromosome.at(chromosome.size() - 1));
    str += ")";
    return str;
}

std::vector<int>& IntegerVector::getChromosome() {
    return chromosome;
}

IntegerVector* IntegerVector::clone() const {
    return new IntegerVector(*this);
}

IntegerVector::IntegerVector(const IntegerVector &obj) : Genotype(obj) {
    this->chromosome = obj.chromosome;
}