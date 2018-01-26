#include "SimpleBuilder.h"
#include "SimpleIndividual.h"

SimpleBuilder::SimpleBuilder(const core::Configuration &configuration, Individual &individual) : Builder(configuration, individual) {}

SimpleBuilder* SimpleBuilder::clone() const {
    return new SimpleBuilder(*this);
}

void SimpleBuilder::initialize(Individual &ind, Thread &thread) const {
    dynamic_cast<SimpleIndividual &>(ind).setLabel("passed");
}