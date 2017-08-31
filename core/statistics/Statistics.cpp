#include "Statistics.h"
#include "../../cc/toolbox/ec/common/RawFitness.h"

using namespace boost::python;

Statistics::Statistics(Session &session) {
    best_fitnesses = vector<float>(session.generations() + 1);
    average_fitnesses = vector<float>(session.generations() + 1);
    worst_fitnesses = vector<float>(session.generations() + 1);
}

void Statistics::record(Population &pop, unsigned int generation) {
    best_fitnesses.at(generation) = dynamic_cast<RawFitness &>(pop.bestIndividual()->getFitness()).getFitness();
    worst_fitnesses.at(generation) = dynamic_cast<RawFitness &>(pop.worstIndividual()->getFitness()).getFitness();
    average_fitnesses.at(generation) = averageFitness(pop);
}

float Statistics::averageFitness(Population &pop) {
    vector<Individual *> &individuals = pop.getIndividuals();
    float total_fitness = 0;
    for (auto ind : individuals)
        total_fitness += dynamic_cast<RawFitness &>(ind->getFitness()).getFitness();
    return total_fitness / individuals.size();
}

vector<float> Statistics::bestFitnesses() {
    return best_fitnesses;
}

vector<float> Statistics::averageFitnesses() {
    return average_fitnesses;
}

vector<float> Statistics::worstFitnesses() {
    return worst_fitnesses;
}