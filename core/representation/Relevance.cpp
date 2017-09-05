#include "Relevance.h"

Relevance::Relevance(Relevance &obj) : Prototype(obj) {
    this->fitness = dynamic_cast<Fitness *>(obj.getFitness().clone());
}

Relevance::Relevance(Session &session) : Prototype(session) {
    fitness = session.fitness();
    EPOCHS = session.epochs();
}

Relevance::~Relevance() {
    delete fitness;
}

Fitness & Relevance::getFitness() {
    return *fitness;
}