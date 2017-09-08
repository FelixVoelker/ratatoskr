#include <iostream>
#include "Population.h"

Population::Population(const Session &session) : Singleton(session) {
    builder = session.builder();
    individuals = vector<Individual *>();
    individuals.reserve(session.problem().popsize());
}

Population::~Population() {
    for (auto ind : individuals)
        delete ind;
}

Individual * Population::bestIndividual() const {
    Individual *best_individual = individuals.at(0);
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance().getFitness() > best_individual->getRelevance().getFitness()) {
            best_individual = individuals.at(k);
        }
    }
    return best_individual;
}

Individual * Population::worstIndividual() const {
    Individual *worst_individual = individuals.at(0);
    for (int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance().getFitness() < worst_individual->getRelevance().getFitness()) {
            worst_individual = individuals.at(k);
        }
    }
    return worst_individual;
}

void Population::populate() {
    individuals.clear();
    for (int k = 0; k < individuals.capacity(); k++) {
        individuals.push_back(builder->build());
    }
}

vector<Individual *> & Population::getIndividuals() {
    return individuals;
}