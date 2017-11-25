#include "FitnessWrapper.h"

FitnessWrapper::FitnessWrapper(boost::shared_ptr<Session> session) : Fitness(*session) {}

bool FitnessWrapper::isIdeal() const {
    if (override isIdeal = this->get_override("isideal"))
        return isIdeal();
    return Fitness::isIdeal();
}

bool FitnessWrapper::default_isIdeal() const { return this->Fitness::isIdeal(); }

bool FitnessWrapper::operator<(const Fitness &other) const {
    if (override o = this->get_override("operator<"))
        return o(other);
    return Fitness::operator<(other);
}

bool FitnessWrapper::default_lt(const Fitness &other) const { return Fitness::operator<(other); }

bool FitnessWrapper::operator<=(const Fitness &other) const {
    if (override o = this->get_override("operator<="))
        return o(other);
    return Fitness::operator<=(other);
}

bool FitnessWrapper::default_leq(const Fitness &other) const { return Fitness::operator<=(other); }

bool FitnessWrapper::operator>(const Fitness &other) const {
    if (override o = this->get_override("operator>"))
        return o(other);
    return Fitness::operator>(other);
}

bool FitnessWrapper::default_gt(const Fitness &other) const { return Fitness::operator>(other); }

bool FitnessWrapper::operator>=(const Fitness &other) const {
    if (override o = this->get_override("operator>="))
        return o(other);
    return Fitness::operator>=(other);
}

bool FitnessWrapper::default_geq(const Fitness &other) const { return Fitness::operator>=(other); }

bool FitnessWrapper::operator==(const Fitness &other) const {
    if (override o = this->get_override("operator=="))
        return o(other);
    return Fitness::operator==(other);
}

bool FitnessWrapper::default_eq(const Fitness &other) const { return Fitness::operator==(other); }