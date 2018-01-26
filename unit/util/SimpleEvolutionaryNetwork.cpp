#include "SimpleEvolutionaryNetwork.h"

SimpleEvolutionaryNetwork::SimpleEvolutionaryNetwork(const core::Configuration &configuration) : EvolutionaryNetwork(configuration) {}

std::vector<float> SimpleEvolutionaryNetwork::output(std::vector<Individual *> &individuals) const {
    return std::vector<float>(individuals.size());
}

void SimpleEvolutionaryNetwork::update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) {}

SimpleEvolutionaryNetwork* SimpleEvolutionaryNetwork::clone() const {
    return new SimpleEvolutionaryNetwork(*this);
}

std::vector<unsigned int> SimpleEvolutionaryNetwork::preprocess(std::vector<Individual *> &individuals) const {
    return std::vector<unsigned int>(individuals.size());
}