#include "TransitionTable.h"
#include "Problem.h"
#include "VectorIndividual.h"

TransitionTable::TransitionTable(const common::Configuration &configuration) :
        EvolutionaryNetwork(configuration),
        lookup_table(std::vector<float>(
                static_cast<unsigned long>(pow(2, dynamic_cast<const common::Configuration::ProblemConfiguration &>(
                                        configuration.getProblemConfiguration()).genes)), 0))
{
}

std::vector<float> TransitionTable::output(std::vector<Individual *> &individuals) const {
    std::vector<float> cost = std::vector<float>(individuals.size());
    std::vector<unsigned int> indices = preprocess(individuals);
    for (unsigned int k = 0; k < individuals.size(); k++) {
        cost.at(k) = lookup_table.at(indices.at(k));
    }
    return cost;
}

void TransitionTable::update(std::vector<float> &fitness,
                             std::vector<std::vector<float>> &parent,
                             std::vector<std::vector<float>> &offspring) {
    auto parent_indices = std::vector<unsigned int>(fitness.size());
    auto offspring_indices = std::vector<unsigned int>(fitness.size());

    for (unsigned int k = 0; k < parent_indices.size(); k++) {
        std::vector<float> chromosome = parent.at(k);
        unsigned int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++) {
            index += chromosome.at(l) * pow(2, chromosome.size() - l - 1);
        }
        parent_indices.at(k) = index;

        chromosome = offspring.at(k);
        index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++) {
            index += chromosome.at(l) * pow(2, chromosome.size() - l - 1);
        }
        offspring_indices.at(k) = index;
    }

    for (unsigned int k = 0; k < fitness.size(); k++) {
        unsigned int index = parent_indices.at(k);
        float precost = lookup_table.at(parent_indices.at(k));
        float postcost = lookup_table.at(offspring_indices.at(k));
        float f = fitness.at(k);

        if (f > 0)
            lookup_table.at(parent_indices.at(k)) = precost + learning_rate * (f + discount_factor * postcost - precost);
    }
}

EvolutionaryNetwork* TransitionTable::clone() const {
    return new TransitionTable(*this);
}

TransitionTable::TransitionTable(const TransitionTable &obj) : EvolutionaryNetwork(obj) {
    this->lookup_table = std::vector<float>(obj.lookup_table);
}

std::vector<unsigned int> TransitionTable::preprocess(std::vector<Individual *> &individuals) const {
    auto indices = std::vector<unsigned int>(individuals.size());
    for (unsigned int k = 0; k < individuals.size(); k++) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual *>(individuals.at(k))->getChromosome();
        unsigned int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++) {
            index += chromosome.at(l) * pow(2, chromosome.size() - l - 1);
        }
        indices.at(k) = index;
    }
    return indices;
}