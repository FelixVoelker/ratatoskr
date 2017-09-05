#include <iostream>
#include "BitVectorIndividual.h"

BitVectorIndividual::BitVectorIndividual(NDGASession &session) : Individual(session) {
    unsigned int genes = dynamic_cast<NDGAProblem *>(&session.problem())->genes;
    this->chromosome = vector<unsigned int>(genes);
}

BitVectorIndividual::BitVectorIndividual(BitVectorIndividual &obj) : Individual(obj) {
    this->chromosome = obj.chromosome;
}

string BitVectorIndividual::toString() {
    string str = "";
    for (int k = 0; k < chromosome.size(); k++) {
        str += to_string(chromosome.at(k));
    }
    return str;
}

vector<unsigned int> & BitVectorIndividual::getChromosome() {
    return chromosome;
}

BitVectorIndividual * BitVectorIndividual::clone() {
    return new BitVectorIndividual(*this);
}