#include "BuilderWrapper.h"

BuilderWrapper::BuilderWrapper(Configuration &configuration, Individual *prototype) : Builder(configuration, prototype) {}

void BuilderWrapper::initialize(Individual &ind) const {
    this->get_override("initialize")();
}