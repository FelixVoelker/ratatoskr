#include "Relevance.h"

Relevance::Relevance() : Clonable() {
    this->criticism = 0;
    this->fitness = 0;
}

bool Relevance::isIdeal() const {
    return fitness == 0;
}

float Relevance::compute() const {
    return fitness + criticism;
}

float Relevance::adjustedRelevance() const {
    return 1 / (1 + fitness + criticism);
}

bool Relevance::operator<(const Relevance &other) const {
    return this->compute() > other.compute();
}

bool Relevance::operator<=(const Relevance &other) const {
    return this->compute() >= other.compute();
}

bool Relevance::operator>(const Relevance &other) const {
    return this->compute() < other.compute();
}

bool Relevance::operator>=(const Relevance &other) const {
    return this->compute() <= other.compute();
}

bool Relevance::operator==(const Relevance &other) const {
    return this->compute() == other.compute();
}

bool Relevance::operator!=(const Relevance &other) const {
    return this->compute() != other.compute();
}

Relevance* Relevance::clone() const {
    return new Relevance(*this);
}

float Relevance::getCriticism() const {
    return criticism;
}

float Relevance::getFitness() const {
    return fitness;
}

void Relevance::setCriticism(float criticism) {
    this->criticism = criticism;
}

void Relevance::setFitness(float fitness) {
    this->fitness = fitness;
}

Relevance::Relevance(const Relevance &obj) : Clonable(obj) {
    this->criticism = obj.criticism;
    this->fitness = obj.fitness;
}