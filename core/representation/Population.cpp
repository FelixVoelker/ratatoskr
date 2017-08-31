#include <iostream>
#include "Population.h"

Population::Population(Session &session) : Singleton(session) {
    builder = session.builder();
    individuals = vector<Individual *>();
    individuals.reserve(session.problem().popsize());
}

Population::~Population() {
    for (auto ind : individuals)
        delete ind;
}

Individual* Population::bestIndividual() {
    Individual *best_individual = individuals.at(0);
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getFitness() > best_individual->getFitness()) {
            best_individual = individuals.at(k);
        }
    }
    return best_individual;
}

Individual* Population::worstIndividual() {
    Individual *worst_individual = individuals.at(0);
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getFitness() < worst_individual->getFitness()) {
            worst_individual = individuals.at(k);
        }
    }
    return worst_individual;
}

void Population::populate() {
    individuals.clear();
    for (int k = 0; k < individuals.capacity(); k++) {
        individuals.push_back((*builder)->build());
    }
}

vector<Individual *> & Population::getIndividuals() {
    return individuals;
}