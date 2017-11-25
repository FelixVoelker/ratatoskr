#include "TestIndividual.h"

TestIndividual::TestIndividual(Session &session) : Individual(session) {}

TestIndividual * TestIndividual::clone() const {
    return new TestIndividual(*this);
}

string TestIndividual::toString() { return ""; }
