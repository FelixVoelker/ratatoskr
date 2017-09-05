#include "RawFitness.h"

RawFitness::RawFitness(Session &session) : Fitness(session) {}

bool RawFitness::isIdeal() {
    return false;
}

bool RawFitness::operator<(Fitness &other) {
    return this->_fitness < ((RawFitness &) other)._fitness;
}

bool RawFitness::operator<=(Fitness &other) {
    return this->_fitness <= ((RawFitness &) other)._fitness;
}

bool RawFitness::operator>(Fitness &other) {
    return this->_fitness > ((RawFitness &) other)._fitness;
}

bool RawFitness::operator>=(Fitness &other) {
    return this->_fitness >= ((RawFitness &) other)._fitness;
}

bool RawFitness::operator==(Fitness &other) {
    return this->_fitness == ((RawFitness &) other)._fitness;
}

float RawFitness::fitness() {
    return _fitness;
}

float RawFitness::standarizedFitness() {
    return _standarized_fitness;
}

void RawFitness::fitness(float fitness) {
    this->_fitness = fitness;
}

void RawFitness::standarizedFitness(float standarizedFitness) {
    this->_standarized_fitness = standarizedFitness;
}


RawFitness * RawFitness::clone() {
    return new RawFitness(*this);
}

