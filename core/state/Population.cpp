#include "Population.h"

Population::Population(const EvolutionarySystem &system, unsigned int popsize) {
    auto *relevance = new Relevance();
    individuals = std::vector<Individual>(popsize);
    for (unsigned int k = 0; k < popsize; k++) {
        individuals.at(k) = Individual(system.getGenotype(), *relevance);
    }
    delete relevance;
}

const Individual Population::bestIndividual() const {
    Individual best_individual = individuals.at(0);
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k).getRelevance() > best_individual.getRelevance())
            best_individual = individuals.at(k);
    }
    return best_individual;
}

const Individual Population::averageIndividual() const {
    float average_criticism = individuals.at(0).getRelevance().getCriticism();
    float average_fitness = individuals.at(0).getRelevance().getFitness();
    for (unsigned int k = 1; k < individuals.size(); k++) {
        average_criticism += individuals.at(k).getRelevance().getCriticism();
        average_fitness += individuals.at(k).getRelevance().getFitness();
    }
    Individual individual = individuals.at(0);
    individual.getRelevance().setCriticism(average_criticism / individuals.size());
    individual.getRelevance().setFitness(average_fitness / individuals.size());
    return individual;
}

const Individual & Population::worstIndividual() const {
    Individual worst_individual = individuals.at(0);
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k).getRelevance() < worst_individual.getRelevance())
            worst_individual = individuals.at(k);
    }
    return worst_individual;
}

std::vector<Individual> & Population::getIndividuals() {
    return this->individuals;
}