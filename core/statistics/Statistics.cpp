#include "Statistics.h"

Statistics::Statistics(const core::Configuration &configuration) {
    epochs = configuration.getEvolutionarySystemConfiguration().epochs;
    episodes = configuration.getEvolutionarySystemConfiguration().episodes;

    auto f = std::vector<float>(configuration.getEvolutionarySystemConfiguration().generations + 1, 0);
    best_costs = std::vector<std::vector<float>>(epochs, f);
    best_fitnesses = std::vector<std::vector<float>>(epochs, f);
    best_relevances = std::vector<std::vector<float>>(epochs, f);
    average_costs = std::vector<std::vector<float>>(epochs, f);
    average_fitnesses = std::vector<std::vector<float>>(epochs, f);
    average_relevances = std::vector<std::vector<float>>(epochs, f);
    worst_costs = std::vector<std::vector<float>>(epochs, f);
    worst_fitnesses = std::vector<std::vector<float>>(epochs, f);
    worst_relevances = std::vector<std::vector<float>>(epochs, f);
}

Statistics::~Statistics() {
    std::vector<std::vector<float>>().swap(best_costs);
    std::vector<std::vector<float>>().swap(best_fitnesses);
    std::vector<std::vector<float>>().swap(best_relevances);
    std::vector<std::vector<float>>().swap(average_costs);
    std::vector<std::vector<float>>().swap(average_fitnesses);
    std::vector<std::vector<float>>().swap(average_relevances);
    std::vector<std::vector<float>>().swap(worst_costs);
    std::vector<std::vector<float>>().swap(worst_fitnesses);
    std::vector<std::vector<float>>().swap(worst_relevances);
}

void Statistics::record(Population &pop, const unsigned int epoch, const unsigned int generation) {
    best_costs.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().getCost() / episodes;
    best_fitnesses.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().getFitness() / episodes;
    best_relevances.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().relevance() / episodes;
    average_costs.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().getCost() / episodes;
    average_fitnesses.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().getFitness() / episodes;
    average_relevances.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().relevance() / episodes;
    worst_costs.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().getCost() / episodes;
    worst_fitnesses.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().getFitness() / episodes;
    worst_relevances.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().relevance() / episodes;
}

std::vector<float> Statistics::bestCosts(unsigned int epoch) const {
    return best_costs.at(epoch);
}

std::vector<float> Statistics::bestFitnesses(const unsigned int epoch) const {
    return best_fitnesses.at(epoch);
}

std::vector<float> Statistics::bestRelevances(unsigned int epoch) const {
    return best_relevances.at(epoch);
}

std::vector<float> Statistics::averageCosts(unsigned int epoch) const {
    return average_costs.at(epoch);
}

std::vector<float> Statistics::averageFitnesses(const unsigned int epoch) const {
    return average_fitnesses.at(epoch);
}

std::vector<float> Statistics::averageRelevances(unsigned int epoch) const {
    return average_relevances.at(epoch);
}

std::vector<float> Statistics::worstCosts(unsigned int epoch) const {
    return worst_costs.at(epoch);
}

std::vector<float> Statistics::worstFitnesses(const unsigned int epoch) const {
    return worst_fitnesses.at(epoch);
}

std::vector<float> Statistics::worstRelevances(unsigned int epoch) const {
    return worst_relevances.at(epoch);
}