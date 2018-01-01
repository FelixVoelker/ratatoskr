#include "BreedingOperatorWrapper.h"

BreedingOperatorWrapper::BreedingOperatorWrapper(boost::shared_ptr<Session> session) : BreedingOperator(*session) {}

unsigned long BreedingOperatorWrapper::expectedSources() const {
    return this->get_override("expectedSources")();
}

std::vector<Individual *> & BreedingOperatorWrapper::breed(std::vector<Individual *> &parents, Thread &thread) const {
    return this->get_override("breed")(parents, thread);
}