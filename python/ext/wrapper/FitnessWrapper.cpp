#include "FitnessWrapper.h"

FitnessWrapper::FitnessWrapper(const core::Configuration &configuration) : Fitness(configuration) {}

bool FitnessWrapper::isIdeal() const {
    if (override isIdeal = this->get_override("isIdeal"))
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

bool FitnessWrapper::operator!=(const Fitness &other) const {
    if (override o = this->get_override("operator!="))
        return o(other);
    return Fitness::operator!=(other);
}

bool FitnessWrapper::default_neq(const Fitness &other) const { return Fitness::operator!=(other); }