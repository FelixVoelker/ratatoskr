#include "FitnessWrapper.h"

FitnessWrapper::FitnessWrapper(boost::shared_ptr<Session> session) : Fitness(*session) {}

bool FitnessWrapper::isIdeal() {
    return this->get_override("isideal")();
}

bool FitnessWrapper::operator<(Fitness &other) {
    return this->get_override("operator<")(other);
}

bool FitnessWrapper::operator<=(Fitness &other) {
    return this->get_override("operator<=")(other);
}

bool FitnessWrapper::operator>(Fitness &other) {
    return this->get_override("operator>")(other);
}

bool FitnessWrapper::operator>=(Fitness &other) {
    return this->get_override("operator>=")(other);
}

bool FitnessWrapper::operator==(Fitness &other) {
    return this->get_override("operator==")(other);
}

Fitness* FitnessWrapper::clone() {
    return this->get_override("clone")();
}