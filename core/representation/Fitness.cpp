#include "Fitness.h"

Fitness::Fitness(const Session &session) : Prototype(session) {}

bool Fitness::isIdeal() const {
    return fitness == 0;
}

bool Fitness::operator<(const Fitness &other) const {
    return this->fitness > other.fitness;
}

bool Fitness::operator<=(const Fitness &other) const {
    return this->fitness >= other.fitness;
}

bool Fitness::operator>(const Fitness &other) const {
    return this->fitness < other.fitness;
}

bool Fitness::operator>=(const Fitness &other) const {
    return this->fitness <= other.fitness;
}

bool Fitness::operator==(const Fitness &other) const {
    return this->fitness == other.fitness;
}

bool Fitness::operator!=(const Fitness &other) const {
    return this->fitness != other.fitness;
}

Fitness * Fitness::clone() const {
    return new Fitness(*this);
}

float Fitness::getFitness() const {
    return fitness;
}

void Fitness::setFitness(const float fitness) {
    this->fitness = fitness;
}

Fitness::Fitness(const Fitness &obj) : Prototype(obj) {
    this->fitness = obj.fitness;
}