#include "Statistics.h"
#include "../../cc/ec/common/RawFitness.h"

using namespace boost::python;

Statistics::Statistics(Session &session) {
    episodes = session.episodes();
    best_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1));
    average_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1));
    worst_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1));
}

void Statistics::record(Population &pop, unsigned int epoch, unsigned int generation) {
    best_fitnesses.at(epoch).at(generation) = dynamic_cast<RawFitness &>(pop.bestIndividual()->getRelevance().getFitness()).fitness() / episodes;
    worst_fitnesses.at(epoch).at(generation) = dynamic_cast<RawFitness &>(pop.worstIndividual()->getRelevance().getFitness()).fitness() / episodes;
    average_fitnesses.at(epoch).at(generation) = averageFitness(pop) / episodes;
}

float Statistics::averageFitness(Population &pop) {
    vector<Individual *> &individuals = pop.getIndividuals();
    float total_fitness = 0;
    for (auto ind : individuals)
        total_fitness += dynamic_cast<RawFitness &>(ind->getRelevance().getFitness()).fitness();
    return total_fitness / individuals.size();
}

vector<float> Statistics::bestFitnesses(int epoch) {
    return best_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::bestFitnesses() {
    return best_fitnesses;
}

vector<float> Statistics::averageFitnesses(int epoch) {
    return average_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::averageFitnesses() {
    return average_fitnesses;
}

vector<float> Statistics::worstFitnesses(int epoch) {
    return worst_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::worstFitnesses() {
    return worst_fitnesses;
}