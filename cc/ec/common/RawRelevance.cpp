#include "RawRelevance.h"
#include "RawFitness.h"

RawRelevance::RawRelevance(const Session &session) : Relevance(session) {}

float RawRelevance::relevance(int epoch) {
    float fraction = epoch < epochs? epoch / epochs : 1;
    return 1 / (1 + (1 - fraction) * dynamic_cast<RawFitness *>(fitness)->fitness() + fraction * _cost);
}

float RawRelevance::cost() const {
    return _cost;
}

void RawRelevance::cost(const float cost) {
    this->_cost = cost;
}

RawRelevance* RawRelevance::clone() const {
    return new RawRelevance(*this);
}