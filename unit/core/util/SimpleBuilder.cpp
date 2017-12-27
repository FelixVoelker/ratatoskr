#include "SimpleBuilder.h"
#include "SimpleIndividual.h"

SimpleBuilder::SimpleBuilder(Session &session) : Builder(session) {}

void SimpleBuilder::initialize(Individual &ind) const {
    dynamic_cast<SimpleIndividual &>(ind).setLabel("passed");
}