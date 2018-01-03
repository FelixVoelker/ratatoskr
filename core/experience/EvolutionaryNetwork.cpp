#include "EvolutionaryNetwork.h"

EvolutionaryNetwork::EvolutionaryNetwork(const Session &session) : Singleton(session) {
    learning_rate = session.getLearningRate();
    discount_factor = session.getDiscountFactor();
}