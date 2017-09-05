#include <cmath>
#include "EvolutionaryNetwork.h"
#include "../../cc/ec/ndga/NDGAProblem.h"
#include "../../cc/ec/ndga/BitVectorIndividual.h"
#include "../../cc/ec/common/RawFitness.h"

EvolutionaryNetwork::EvolutionaryNetwork(Session &session) : Singleton(session) {
    learning_rate = session.learning_rate();
    discount_factor = session.discount_factor();
    lookup_table = new vector<vector<float>>(session.problem().popsize(),
                        vector<float>(static_cast<unsigned long>(pow(2,
                                 dynamic_cast<NDGAProblem &>(session.problem()).genes)), 0));
}

vector<float> EvolutionaryNetwork::output(Population &population) {
    vector<Individual *> &individuals = population.getIndividuals();
    vector<float> cost = vector<float>(lookup_table->size());
    for (unsigned int k = 0; k < cost.size(); k++) {
        vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual *>(individuals.at(k))->getChromosome();
        int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++)
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);

        cost.at(k) = lookup_table->at(k).at(index);
    }
    return cost;
}

void EvolutionaryNetwork::update(Population &pop, vector<Individual *> old) {
    vector<Individual *> &inds = pop.getIndividuals();
    for (int k = 0; k < lookup_table->size(); k++) {
        vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual *>(inds.at(k))->getChromosome();
        int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++)
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);
        float newValue = lookup_table->at(k).at(index);

        chromosome = dynamic_cast<BitVectorIndividual *>(old.at(k))->getChromosome();
        index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++)
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);
        float oldValue = lookup_table->at(k).at(index);

        lookup_table->at(k).at(index) = oldValue
                                        + learning_rate
                                          * (dynamic_cast<RawFitness &>(inds.at(k)->getRelevance().getFitness()).standarizedFitness()
                                             + discount_factor * newValue - oldValue);

    }
}