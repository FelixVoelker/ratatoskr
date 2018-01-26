#include "TransitionTable.h"
#include "Problem.h"
#include "VectorIndividual.h"

TransitionTable::TransitionTable(const common::Configuration &configuration) :
        EvolutionaryNetwork(configuration),
        lookup_table(std::vector<std::vector<float>>(
                configuration.getProblemConfiguration().popsize,
                std::vector<float>(static_cast<unsigned long>(
                                           pow(2, dynamic_cast<const common::Configuration::ProblemConfiguration &>(
                                                   configuration.getProblemConfiguration()).genes)), 0)) )
{
}

std::vector<float> TransitionTable::output(std::vector<Individual *> &individuals) const {
    std::vector<float> cost = std::vector<float>(lookup_table.size());
    std::vector<unsigned int> indices = preprocess(individuals);
    for (unsigned int k = 0; k < individuals.size(); k++) {
        cost.at(k) = lookup_table.at(k).at(indices.at(k));
    }
    return cost;
}

void TransitionTable::update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) {
    std::vector<unsigned int> parent_indices = preprocess(parents);
    std::vector<unsigned int> offspring_indices = preprocess(offsprings);

    for (unsigned int k = 0; k < lookup_table.size(); k++) {
        float precost = lookup_table.at(k).at(parent_indices.at(k));
        float postcost = lookup_table.at(k).at(offspring_indices.at(k));
        float fitness = parents.at(k)->getRelevance().getFitness();
        lookup_table.at(k).at(parent_indices.at(k)) = precost + learning_rate * (fitness + discount_factor * postcost - precost);
    }
}

EvolutionaryNetwork* TransitionTable::clone() const {
    return new TransitionTable(*this);
}

TransitionTable::TransitionTable(const TransitionTable &obj) : EvolutionaryNetwork(obj) {
    this->lookup_table = std::vector<std::vector<float>>(obj.lookup_table);
}

std::vector<unsigned int> TransitionTable::preprocess(std::vector<Individual *> &individuals) const {
    auto indices = std::vector<unsigned int>(individuals.size());
    for (unsigned int k = 0; k < individuals.size(); k++) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual *>(individuals.at(k))->getChromosome();
        unsigned int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++) {
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);
        }
        indices.at(k) = index;
    }
    return indices;
}