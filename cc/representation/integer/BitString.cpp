#include "BitString.h"

BitString::BitString(unsigned int genes) : Genotype() {
    this->chromosome = std::vector<bool>(genes);
}

std::string BitString::toString() {
    std::string str;
    for (auto gene : chromosome) {
        str += std::to_string((unsigned int) gene);
    }
    return str;
}

std::vector<bool> & BitString::getChromosome() {
    return chromosome;
}

BitString * BitString::clone() const {
    return new BitString(*this);
}

BitString::BitString(const BitString &obj) : Genotype(obj) {
    this->chromosome = obj.chromosome;
}