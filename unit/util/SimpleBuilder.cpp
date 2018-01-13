#include "SimpleBuilder.h"
#include "SimpleIndividual.h"

SimpleBuilder::SimpleBuilder(const core::Configuration &configuration, Individual *individual) : Builder(configuration, individual) {}

void SimpleBuilder::initialize(Individual &ind, Thread &thread) const {
    dynamic_cast<SimpleIndividual &>(ind).setLabel("passed");
}