#include "Population.h"

Population::Population(Configuration &configuration) : Singleton(configuration) {
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
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getFitness() > best_individual->getFitness())
            best_individual = individuals.at(k);
    }
    return best_individual;
}

Individual * Population::averageIndividual() const {
    float average_cost = individuals.at(0)->getCost().getCost();
    float average_fitness = individuals.at(0)->getFitness().getFitness();
    for (int k = 1; k < individuals.size(); k++) {
        average_cost += individuals.at(k)->getCost().getCost();
        average_fitness += individuals.at(k)->getFitness().getFitness();
    }
    Individual *average_individual = individuals.at(0)->clone();
    average_individual->getCost().setCost(average_cost / individuals.size());
    average_individual->getFitness().setFitness(average_fitness / individuals.size());
    return average_individual;
}

Individual * Population::worstIndividual() const {
    Individual *worst_individual = individuals.at(0);
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getFitness() < worst_individual->getFitness())
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