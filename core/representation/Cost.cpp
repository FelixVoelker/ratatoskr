#include "Cost.h"

Cost::Cost(const Cost &obj) : Prototype(obj) {}

Cost::Cost(const Session &session) : Prototype(session) {}

Cost * Cost::clone() const {
    return new Cost(*this);
}

float Cost::getApproximateCost() const {
    return approximateCost;
}

void Cost::setApproximateCost(const float cost) {
    this->approximateCost = cost;
}

