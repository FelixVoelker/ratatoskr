#include "Relevance.h"

Relevance::Relevance(const core::Configuration &configuration) : Prototype(configuration) {}

float Relevance::error(float discount_factor, float fitness, float next) const {
    return fitness + discount_factor*next - cost;
}

bool Relevance::isIdeal() const {
    return fitness == 0;
}

float Relevance::relevance() const {
    return (1 - fraction) * fitness + fraction * cost;
}

float Relevance::adjustedRelevance() const {
    return 1 / (1 + relevance());
}

bool Relevance::operator<(const Relevance &other) const {
    return this->relevance() > other.relevance();
}

bool Relevance::operator<=(const Relevance &other) const {
    return this->relevance() >= other.relevance();
}

bool Relevance::operator>(const Relevance &other) const {
    return this->relevance() < other.relevance();
}

bool Relevance::operator>=(const Relevance &other) const {
    return this->relevance() <= other.relevance();
}

bool Relevance::operator==(const Relevance &other) const {
    return this->relevance() == other.relevance();
}

bool Relevance::operator!=(const Relevance &other) const {
    return this->relevance() != other.relevance();
}

Relevance* Relevance::clone() const {
    return new Relevance(*this);
}

float Relevance::getCost() const {
    return cost;
}

float Relevance::getFitness() const {
    return fitness;
}

float Relevance::getFraction() const {
    return fraction;
}

void Relevance::setCost(float cost) {
    this->cost = cost;
}

void Relevance::setFitness(float fitness) {
    this->fitness = fitness;
}

void Relevance::setFraction(float fraction) {
    fraction = fraction < 0? 0 : fraction;
    fraction = fraction > 1? 1 : fraction;
    this->fraction = fraction;
}

Relevance::Relevance(const Relevance &obj) : Prototype(obj) {
    this->cost = obj.cost;
    this->fitness = obj.fitness;
    this->fraction = obj.fraction;
}