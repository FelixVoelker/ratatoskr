#include "Fitness.h"

Fitness::Fitness(const Session &session) : Prototype(session) {}

bool Fitness::isIdeal() const {
    return _fitness == 0;
}

bool Fitness::operator<(const Fitness &other) const {
    return this->_fitness > other._fitness;
}

bool Fitness::operator<=(const Fitness &other) const {
    return this->_fitness >= other._fitness;
}

bool Fitness::operator>(const Fitness &other) const {
    return this->_fitness < other._fitness;
}

bool Fitness::operator>=(const Fitness &other) const {
    return this->_fitness <= other._fitness;
}

bool Fitness::operator==(const Fitness &other) const {
    return this->_fitness == other._fitness;
}

float Fitness::fitness() const {
    return _fitness;
}

void Fitness::fitness(const float fitness) {
    this->_fitness = fitness;
}

Fitness * Fitness::clone() const {
    return new Fitness(*this);
}