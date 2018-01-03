#include "Statistics.h"

Statistics::Statistics(Session &session) {
    episodes = session.getEpisodes();

    auto f = std::vector<float>(session.getGenerations() + 1, 0);
    best_fitnesses = std::vector<std::vector<float>>(session.getEpochs(), f);
    average_fitnesses = std::vector<std::vector<float>>(session.getEpochs(), f);
    worst_fitnesses = std::vector<std::vector<float>>(session.getEpochs(), f);
}

Statistics::~Statistics() {
    std::vector<std::vector<float>>().swap(best_fitnesses);
    std::vector<std::vector<float>>().swap(average_fitnesses);
    std::vector<std::vector<float>>().swap(worst_fitnesses);
}

void Statistics::record(Population &pop, const unsigned int epoch, const unsigned int generation) {
    best_fitnesses.at(epoch).at(generation) += pop.bestIndividual()->getFitness().getFitness() / episodes;
    average_fitnesses.at(epoch).at(generation) += pop.averageIndividual()->getFitness().getFitness() / episodes;
    worst_fitnesses.at(epoch).at(generation) += pop.worstIndividual()->getFitness().getFitness() / episodes;

}

std::vector<float> Statistics::bestFitnesses(const unsigned int epoch) const {
    return best_fitnesses.at(epoch);
}

std::vector<float> Statistics::averageFitnesses(const unsigned int epoch) const {
    return average_fitnesses.at(epoch);
}

std::vector<float> Statistics::worstFitnesses(const unsigned int epoch) const {
    return worst_fitnesses.at(epoch);
}