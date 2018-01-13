#include "EvolutionaryNetwork.h"

EvolutionaryNetwork::EvolutionaryNetwork(const core::Configuration &configuration) : Singleton(configuration) {
    discount_factor = configuration.getEvolutionaryNetworkConfiguration().discount_factor;
    learning_rate = configuration.getEvolutionaryNetworkConfiguration().learning_rate;
}