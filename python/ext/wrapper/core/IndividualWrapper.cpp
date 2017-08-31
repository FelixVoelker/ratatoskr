#include "IndividualWrapper.h"

IndividualWrapper::IndividualWrapper(boost::shared_ptr<Session> session) : Individual(*session) {}

string IndividualWrapper::toString() {
    return this->get_override("tostring")();
}

Individual* IndividualWrapper::clone() {
    return this->get_override("clone")();
}