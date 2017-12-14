#include "SimpleIndividual.h"

SimpleIndividual::SimpleIndividual(Session &session) : Individual(session) {}

std::string SimpleIndividual::toString() { return ""; }

SimpleIndividual * SimpleIndividual::clone() const {
    return new SimpleIndividual(*this);
}
