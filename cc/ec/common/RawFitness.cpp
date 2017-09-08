#include "RawFitness.h"

RawFitness::RawFitness(const Session &session) : Fitness(session) {}

bool RawFitness::isIdeal() {
    return _fitness == 0;
}

bool RawFitness::operator<(Fitness &other) {
    return this->_fitness > ((RawFitness &) other)._fitness;
}

bool RawFitness::operator<=(Fitness &other) {
    return this->_fitness >= ((RawFitness &) other)._fitness;
}

bool RawFitness::operator>(Fitness &other) {
    return this->_fitness < ((RawFitness &) other)._fitness;
}

bool RawFitness::operator>=(Fitness &other) {
    return this->_fitness <= ((RawFitness &) other)._fitness;
}

bool RawFitness::operator==(Fitness &other) {
    return this->_fitness == ((RawFitness &) other)._fitness;
}

float RawFitness::fitness() const {
    return _fitness;
}

void RawFitness::fitness(const float fitness) {
    this->_fitness = fitness;
}

RawFitness * RawFitness::clone() const {
    return new RawFitness(*this);
}

