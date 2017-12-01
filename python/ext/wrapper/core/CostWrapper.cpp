#include "CostWrapper.h"

CostWrapper::CostWrapper(boost::shared_ptr<Session> session) : Cost(*session) {}

bool CostWrapper::operator<(const Cost &other) const {
    if (override o = this->get_override("operator<"))
        return o(other);
    return Cost::operator<(other);
}

bool CostWrapper::default_lt(const Cost &other) const { return Cost::operator<(other); }

bool CostWrapper::operator<=(const Cost &other) const {
    if (override o = this->get_override("operator<="))
        return o(other);
    return Cost::operator<=(other);
}

bool CostWrapper::default_leq(const Cost &other) const { return Cost::operator<=(other); }

bool CostWrapper::operator>(const Cost &other) const {
    if (override o = this->get_override("operator>"))
        return o(other);
    return Cost::operator>(other);
}

bool CostWrapper::default_gt(const Cost &other) const { return Cost::operator>(other); }

bool CostWrapper::operator>=(const Cost &other) const {
    if (override o = this->get_override("operator>="))
        return o(other);
    return Cost::operator>=(other);
}

bool CostWrapper::default_geq(const Cost &other) const { return Cost::operator>=(other); }

bool CostWrapper::operator==(const Cost &other) const {
    if (override o = this->get_override("operator=="))
        return o(other);
    return Cost::operator==(other);
}

bool CostWrapper::default_eq(const Cost &other) const { return Cost::operator==(other); }

bool CostWrapper::operator!=(const Cost &other) const {
    if (override o = this->get_override("operator!="))
        return o(other);
    return Cost::operator!=(other);
}

bool CostWrapper::default_neq(const Cost &other) const { return Cost::operator!=(other); }