#include "Population.h"

Population::Population(const core::Configuration &configuration) : Singleton(configuration) {
    individuals = std::vector<Individual *>(configuration.getProblemConfiguration().popsize);
}

Population::~Population() {
    std::vector<Individual *>().swap(individuals);
}

void Population::exterminate() {
    for (auto &individual : individuals) {
        delete individual;
        individual = nullptr;
    }
}

Individual * Population::bestIndividual() const {
    Individual *best_individual = individuals.at(0);
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance() > best_individual->getRelevance())
            best_individual = individuals.at(k);
    }
    return best_individual;
}

Individual * Population::averageIndividual() const {
    float average_cost = individuals.at(0)->getRelevance().getCost();
    float average_fitness = individuals.at(0)->getRelevance().getFitness();
    for (unsigned int k = 1; k < individuals.size(); k++) {
        average_cost += individuals.at(k)->getRelevance().getCost();
        average_fitness += individuals.at(k)->getRelevance().getFitness();
    }
    Individual *average_individual = individuals.at(0)->clone();
    average_individual->getRelevance().setCost(average_cost / individuals.size());
    average_individual->getRelevance().setFitness(average_fitness / individuals.size());
    return average_individual;
}

Individual * Population::worstIndividual() const {
    Individual *worst_individual = individuals.at(0);
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance() < worst_individual->getRelevance())
            worst_individual = individuals.at(k);
    }
    return worst_individual;
}

std::vector<Individual *> & Population::getIndividuals() {
    std::vector<Individual *> &individuals = this->individuals;
    return individuals;
}

void Population::setIndividuals(std::vector<Individual *> &individuals) {
    this->individuals = individuals;
}