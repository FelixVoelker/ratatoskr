#include "BreedingOperatorWrapper.h"

BreedingOperatorWrapper::BreedingOperatorWrapper(const core::Configuration &configuration) : BreedingOperator(configuration) {}

unsigned long BreedingOperatorWrapper::expectedSources() const {
    return this->get_override("expectedSources")();
}

std::vector<Individual *> & BreedingOperatorWrapper::breed(std::vector<Individual *> &parents, Thread &thread) const {
    return this->get_override("breed")(parents, thread);
}

BreedingOperator * BreedingOperatorWrapper::clone() const {
    return this->get_override("clone")();
}