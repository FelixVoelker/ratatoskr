#include "BuilderWrapper.h"

BuilderWrapper::BuilderWrapper(const core::Configuration &configuration, Individual &prototype) : Builder(configuration, prototype) {}

void BuilderWrapper::initialize(Individual &individual, Thread &thread) const {
    this->get_override("initialize")(individual, thread);
}

Builder* BuilderWrapper::clone() const {
    return this->get_override("clone")();
}