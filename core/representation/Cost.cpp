#include "Cost.h"

Cost::Cost(Configuration &configuration) : Prototype(configuration) {}

float Cost::error(float discount_factor, float fitness, float next) const {
    return fitness + discount_factor*next - cost;
}

bool Cost::operator<(const Cost &other) const {
    return this->cost > other.cost;
}

bool Cost::operator<=(const Cost &other) const {
    return this->cost >= other.cost;
}

bool Cost::operator>(const Cost &other) const {
    return this->cost < other.cost;
}

bool Cost::operator>=(const Cost &other) const {
    return this->cost <= other.cost;
}

bool Cost::operator==(const Cost &other) const {
    return this->cost == other.cost;
}

bool Cost::operator!=(const Cost &other) const {
    return this->cost != other.cost;
}

Cost * Cost::clone() const {
    return new Cost(*this);
}

float Cost::getCost() const {
    return cost;
}

void Cost::setCost(float cost) {
    this->cost = cost;
}

Cost::Cost(const Cost &obj) : Prototype(obj) {
    this->cost = obj.cost;
}
