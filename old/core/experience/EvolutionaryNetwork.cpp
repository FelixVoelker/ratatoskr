#include "EvolutionaryNetwork.h"

EvolutionaryNetwork::EvolutionaryNetwork(const core::Configuration &configuration) : Prototype(configuration) {
    discount_factor = configuration.getEvolutionaryNetworkConfiguration().discount_factor;
    learning_rate = configuration.getEvolutionaryNetworkConfiguration().learning_rate;
}

EvolutionaryNetwork::EvolutionaryNetwork(const EvolutionaryNetwork &obj) : Prototype(obj) {
    this->discount_factor = obj.discount_factor;
    this->learning_rate = obj.learning_rate;
}