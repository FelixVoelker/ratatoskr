#include "TransitionTable.h"
#include "NDGAProblem.h"
#include "BitVectorIndividual.h"

TransitionTable::TransitionTable(const Configuration &session) : EvolutionaryNetwork(session) {
    auto problem = dynamic_cast<NDGAProblem &>(session.getProblem());
    lookup_table = new std::vector<std::vector<float>>(
            session.getProblem().getPopsize(),
            std::vector<float>(static_cast<unsigned long>(pow(2, problem.getGenes())), 0)
    );
}

TransitionTable::~TransitionTable() {
    std::vector<std::vector<float>>().swap(*lookup_table);
}

std::vector<float> TransitionTable::output(std::vector<Individual *> &individuals) const {
    std::vector<float> cost = std::vector<float>(lookup_table->size());
    std::vector<unsigned int> indices = preprocess(individuals);
    for (unsigned int k = 0; k < individuals.size(); k++) {
        cost.at(k) = lookup_table->at(k).at(indices.at(k));
    }
    return cost;
}

void TransitionTable::update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) {
    std::vector<unsigned int> parent_indices = preprocess(parents);
    std::vector<unsigned int> offspring_indices = preprocess(offsprings);

    for (unsigned int k = 0; k < lookup_table->size(); k++) {
        float precost = lookup_table->at(k).at(parent_indices.at(k));
        float postcost = lookup_table->at(k).at(offspring_indices.at(k));
        float fitness = parents.at(k)->getFitness().getFitness();
        lookup_table->at(k).at(parent_indices.at(k)) = precost + learning_rate * (fitness + discount_factor * postcost - precost);
    }
}

std::vector<unsigned int> TransitionTable::preprocess(std::vector<Individual *> &individuals) const {
    auto indices = std::vector<unsigned int>(individuals.size());
    for (unsigned int k = 0; k < individuals.size(); k++) {
        std::vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual *>(individuals.at(k))->getChromosome();
        unsigned int index = 0;
        for (unsigned int l = 0; l < chromosome.size(); l++) {
            index += chromosome.at(l) * pow(2, chromosome.size() - l -1);
        }
        indices.at(k) = index;
    }
    return indices;
}