#include "SimpleEvolutionaryNetwork.h"

SimpleEvolutionaryNetwork::SimpleEvolutionaryNetwork(Session &session) : EvolutionaryNetwork(session) {}

std::vector<float> SimpleEvolutionaryNetwork::output(std::vector<Individual *> &individuals) const {
    return std::vector<float>(individuals.size());
}

void SimpleEvolutionaryNetwork::update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) {}

std::vector<unsigned int> SimpleEvolutionaryNetwork::preprocess(std::vector<Individual *> &individuals) const {
    return std::vector<unsigned int>(individuals.size());
}