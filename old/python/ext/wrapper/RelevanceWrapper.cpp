#include "RelevanceWrapper.h"

RelevanceWrapper::RelevanceWrapper(const core::Configuration &configuration) : Relevance(configuration) {}

bool RelevanceWrapper::isIdeal() const {
    if (override isIdeal = this->get_override("isIdeal"))
        return isIdeal();
    return Relevance::isIdeal();
}

bool RelevanceWrapper::default_isIdeal() const { return this->Relevance::isIdeal(); }

bool RelevanceWrapper::operator<(const Relevance &other) const {
    if (override o = this->get_override("operator<"))
        return o(other);
    return Relevance::operator<(other);
}

bool RelevanceWrapper::default_lt(const Relevance &other) const { return Relevance::operator<(other); }

bool RelevanceWrapper::operator<=(const Relevance &other) const {
    if (override o = this->get_override("operator<="))
        return o(other);
    return Relevance::operator<=(other);
}

bool RelevanceWrapper::default_leq(const Relevance &other) const { return Relevance::operator<=(other); }

bool RelevanceWrapper::operator>(const Relevance &other) const {
    if (override o = this->get_override("operator>"))
        return o(other);
    return Relevance::operator>(other);
}

bool RelevanceWrapper::default_gt(const Relevance &other) const { return Relevance::operator>(other); }

bool RelevanceWrapper::operator>=(const Relevance &other) const {
    if (override o = this->get_override("operator>="))
        return o(other);
    return Relevance::operator>=(other);
}

bool RelevanceWrapper::default_geq(const Relevance &other) const { return Relevance::operator>=(other); }

bool RelevanceWrapper::operator==(const Relevance &other) const {
    if (override o = this->get_override("operator=="))
        return o(other);
    return Relevance::operator==(other);
}

bool RelevanceWrapper::default_eq(const Relevance &other) const { return Relevance::operator==(other); }

bool RelevanceWrapper::operator!=(const Relevance &other) const {
    if (override o = this->get_override("operator!="))
        return o(other);
    return Relevance::operator!=(other);
}

bool RelevanceWrapper::default_neq(const Relevance &other) const { return Relevance::operator!=(other); }