#include "IndividualWrapper.h"

IndividualWrapper::IndividualWrapper(boost::shared_ptr<Session> session) : Individual(*session) {}

std::string IndividualWrapper::toString() {
    return this->get_override("toString")();
}

Individual* IndividualWrapper::clone() const {
    return this->get_override("clone")();
}