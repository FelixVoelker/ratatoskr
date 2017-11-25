#include "Relevance.h"

Relevance::Relevance(const Relevance &obj) : Prototype(obj) {
    EPOCHS = obj.EPOCHS;
    this->fitness = obj.fitness->clone();
}

Relevance::Relevance(const Session &session) : Prototype(session) {
    EPOCHS = session.epochs();
    fitness = session.fitness();
}

Relevance::~Relevance() {
    delete fitness;
}

float Relevance::relevance(int epoch) {
    float fraction = epoch < EPOCHS? epoch / EPOCHS : 1;
    return 1 / (1 + (1 - fraction) * fitness->fitness() + fraction * _cost);
}

Fitness & Relevance::getFitness() const {
    return *fitness;
}

float Relevance::cost() const {
    return _cost;
}

void Relevance::cost(const float cost) {
    this->_cost = cost;
}

Relevance * Relevance::clone() const {
    return new Relevance(*this);
}