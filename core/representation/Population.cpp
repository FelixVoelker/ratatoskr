#include "Population.h"

Population::Population(const Session &session) : Singleton(session) {
    builder = session.getBuilder();

    individuals = vector<Individual *>(session.getProblem().popsize());
}

void Population::initialize() {
    for (auto &individual : individuals) {
        individual = builder->build();
    }
}

void Population::finalize() {
    for (auto individual : individuals) {
        delete individual;
    }
}

void Population::changeGeneration(vector<Individual *> *offspring) {
    finalize();
    individuals = *offspring;
    delete offspring;
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

vector<Individual *> Population::getIndividuals() const {
    return individuals;
}