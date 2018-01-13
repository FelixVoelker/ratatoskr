#include "Replayer.h"

Replayer::Replayer(const core::Configuration &configuration, EvolutionaryNetwork *network) : Singleton(configuration) {
    this->network = network;
}

void Replayer::replay(Population &pop, std::vector<Individual *> &offsprings) const {
    network->update(pop.getIndividuals(), offsprings);
}