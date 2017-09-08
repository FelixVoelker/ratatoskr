#include "Statistics.h"
#include "../../cc/ec/common/RawFitness.h"
#include "../../cc/ec/ndga/BitVectorIndividual.h"

using namespace boost::python;

Statistics::Statistics(Session &session) {
    episodes = session.episodes();
    best_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1, 0));
    average_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1, 0));
    worst_fitnesses = vector<vector<float>>(session.epochs(), vector<float>(session.generations() + 1, 0));
}

void Statistics::record(const Population &pop, const unsigned int epoch, const unsigned int generation) {
    best_fitnesses.at(epoch).at(generation) = dynamic_cast<RawFitness &>(pop.bestIndividual()->getRelevance().getFitness()).fitness() / episodes;
    worst_fitnesses.at(epoch).at(generation) = dynamic_cast<RawFitness &>(pop.worstIndividual()->getRelevance().getFitness()).fitness() / episodes;
    average_fitnesses.at(epoch).at(generation) = averageFitness(pop) / episodes;
}

float Statistics::averageFitness(const Population &pop) {
    vector<Individual *> individuals = pop.getIndividuals();
    float total_fitness = 0;
    for (auto ind : individuals)
        total_fitness += dynamic_cast<RawFitness &>(ind->getRelevance().getFitness()).fitness();
    return total_fitness / individuals.size();
}

vector<float> Statistics::bestFitnesses(const int epoch) const {
    return best_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::bestFitnesses() const {
    return best_fitnesses;
}

vector<float> Statistics::averageFitnesses(const int epoch) const {
    return average_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::averageFitnesses() const {
    return average_fitnesses;
}

vector<float> Statistics::worstFitnesses(const int epoch) const {
    return worst_fitnesses.at(epoch);
}

vector<vector<float>> Statistics::worstFitnesses() const {
    return worst_fitnesses;
}