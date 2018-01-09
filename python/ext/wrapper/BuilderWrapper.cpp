#include "BuilderWrapper.h"

BuilderWrapper::BuilderWrapper(Configuration &configuration, Individual *prototype) : Builder(configuration, prototype) {}

void BuilderWrapper::initialize(Individual &individual, Thread &thread) const {
    this->get_override("initialize")(individual, thread);
}