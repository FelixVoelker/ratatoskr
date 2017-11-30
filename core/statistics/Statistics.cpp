#include "Statistics.h"

using namespace boost::python;

Statistics::Statistics(Session &session) {
    episodes = session.getEpisodes();

    vector<float> f = vector<float>(session.getGenerations() + 1, 0);
    best_fitnesses = vector<vector<float>>(session.getEpochs(), f);
    average_fitnesses = vector<vector<float>>(session.getEpochs(), f);
    worst_fitnesses = vector<vector<float>>(session.getEpochs(), f);
}

void Statistics::record(Population &pop, const unsigned int epoch, const unsigned int generation) {
    best_fitnesses.at(epoch).at(generation) = pop.bestIndividual()->getRelevance().getFitness().fitness() / episodes;
    worst_fitnesses.at(epoch).at(generation) = pop.worstIndividual()->getRelevance().getFitness().fitness() / episodes;
    average_fitnesses.at(epoch).at(generation) = averageFitness(pop) / episodes;
}

float Statistics::averageFitness(Population &pop) {
    vector<Individual *> individuals = pop.getIndividuals();
    float total_fitness = 0;
    for (auto ind : individuals)
        total_fitness += ind->getRelevance().getFitness().fitness();
    return total_fitness / individuals.size();
}

vector<float> Statistics::bestFitnesses(const unsigned int epoch) const {
    return best_fitnesses.at(epoch);
}

vector<float> Statistics::averageFitnesses(const unsigned int epoch) const {
    return average_fitnesses.at(epoch);
}

vector<float> Statistics::worstFitnesses(const unsigned int epoch) const {
    return worst_fitnesses.at(epoch);
}