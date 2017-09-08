#include "Relevance.h"

Relevance::Relevance(const Relevance &obj) : Prototype(obj) {
    this->fitness = dynamic_cast<Fitness *>(obj.fitness->clone());
    epochs = obj.epochs;
}

Relevance::Relevance(const Session &session) : Prototype(session) {
    fitness = session.fitness();
    epochs = session.epochs();
}

Relevance::~Relevance() {
    delete fitness;
}

Fitness & Relevance::getFitness() const {
    return *fitness;
}