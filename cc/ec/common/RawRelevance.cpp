#include "RawRelevance.h"
#include "RawFitness.h"

RawRelevance::RawRelevance(Session &session) : Relevance(session) {}

float RawRelevance::relevance(int epoch) {
    float fraction = epoch < EPOCHS? epoch / EPOCHS : 1;
    return 1 / (1 + (1 - fraction) * dynamic_cast<RawFitness *>(fitness)->standarizedFitness() + fraction * _cost);
}

float RawRelevance::cost() {
    return _cost;
}

void RawRelevance::cost(float cost) {
    this->_cost = cost;
}

RawRelevance* RawRelevance::clone() {
    return new RawRelevance(*this);
}