#include "SimpleIndividual.h"

#include <utility>

SimpleIndividual::SimpleIndividual(const core::Configuration &configuration, FeatureMap *featuremap, Relevance *relevance)
        : Individual(configuration, featuremap, relevance)
{
}

std::string SimpleIndividual::toString() { return label; }

void SimpleIndividual::setLabel(std::string label) {
    this->label = std::move(label);
}

SimpleIndividual * SimpleIndividual::clone() const {
    return new SimpleIndividual(*this);
}

SimpleIndividual::SimpleIndividual(const SimpleIndividual &obj) : Individual(obj) {
    this->label = obj.label;
}
