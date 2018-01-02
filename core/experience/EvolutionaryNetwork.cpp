#include <cmath>
#include "EvolutionaryNetwork.h"
#include "../../cc/ec/ndga/NDGAProblem.h"
#include "../../cc/ec/ndga/BitVectorIndividual.h"

EvolutionaryNetwork::EvolutionaryNetwork(const Session &session) : Singleton(session) {
    learning_rate = session.getLearningRate();
    discount_factor = session.getDiscountFactor();
    lookup_table = new vector<vector<float>>(session.getProblem().popsize(),
                        vector<float>(static_cast<unsigned long>(pow(2,
                                 dynamic_cast<const NDGAProblem &>(session.getProblem()).genes)), 0));
}

EvolutionaryNetwork::~EvolutionaryNetwork() {
    delete lookup_table;
}

vector<float> EvolutionaryNetwork::output(const Population &pop) const {
    vector<Individual *> individuals = pop.getIndividuals();
    vector<float> cost = vector<float>(lookup_table->size());
    for (unsigned int k = 0; k < cost.size(); k++) {
        vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual *>(individuals.at(k))->getChromosome();
        unsigned int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++)
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);

        cost.at(k) = lookup_table->at(k).at(index);
    }
    return cost;
}

void EvolutionaryNetwork::update(Population &pop, vector<Individual *> offsprings) {
    vector<Individual *> inds = pop.getIndividuals();
    for (unsigned int k = 0; k < lookup_table->size(); k++) {
        vector<unsigned int> &old_chromosome = dynamic_cast<BitVectorIndividual *>(inds.at(k))->getChromosome();
        unsigned int index = 0;
        for (unsigned int l = 0; l < old_chromosome.size(); l++)
            index += old_chromosome.at(l) * pow(2, old_chromosome.size() - l -1);
        float newValue = lookup_table->at(k).at(index);

        vector<unsigned int> &new_chromosome = dynamic_cast<BitVectorIndividual *>(offsprings.at(k))->getChromosome();
        index = 0;
        for (unsigned int l = 0; l < new_chromosome.size(); l++)
            index += old_chromosome.at(l) * pow(2, new_chromosome.size() - l -1);
        float oldValue = lookup_table->at(k).at(index);

        lookup_table->at(k).at(index) = oldValue
                                        + learning_rate
                                          * (inds.at(k)->getRelevance().getFitness().fitness()
                                             + discount_factor * newValue - oldValue);

    }
}