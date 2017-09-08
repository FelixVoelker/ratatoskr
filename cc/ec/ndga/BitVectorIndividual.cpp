#include <iostream>
#include "BitVectorIndividual.h"

BitVectorIndividual::BitVectorIndividual(const NDGASession &session) : Individual(session) {
    unsigned int genes = dynamic_cast<const NDGAProblem *>(&session.problem())->genes;
    this->chromosome = vector<unsigned int>(genes);
}

BitVectorIndividual::BitVectorIndividual(const BitVectorIndividual &obj) : Individual(obj) {
    this->chromosome = obj.chromosome;
    this->_evaluated = obj.evaluated();
}

string BitVectorIndividual::toString() {
    string str;
    for (unsigned int k : chromosome) {
        str += to_string(k);
    }
    return str;
}

vector<unsigned int> & BitVectorIndividual::getChromosome() {
    return chromosome;
}

BitVectorIndividual * BitVectorIndividual::clone() const {
    return new BitVectorIndividual(*this);
}