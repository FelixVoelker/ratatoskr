#include "Relevance.h"

Relevance::Relevance() : Clonable() {
    this->critic = 0;
    this->fitness = 0;
}

float Relevance::compute() const {
    return fitness + critic;
}

float Relevance::adjustedRelevance() const {
    return 1 / (1 + fitness + critic);
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

float Relevance::getCritic() const {
    return critic;
}

float Relevance::getFitness() const {
    return fitness;
}

void Relevance::setCritic(float critic) {
    this->critic = critic;
}

void Relevance::setFitness(float fitness) {
    this->fitness = fitness;
}

Relevance::Relevance(const Relevance &obj) : Clonable(obj) {
    this->critic = obj.critic;
    this->fitness = obj.fitness;
}