#include <iostream>
#include "EvolutionarySystem.h"

EvolutionarySystem::EvolutionarySystem(Session &session)
        : population(Population(session)),
          evaluator(Evaluator(session)),
          breeder(Breeder(session)),
          statistics(Statistics(session)),
          replayer(Replayer(session)) {
    EPOCHS = session.epochs();
    EPISODES = session.episodes();
    GENERATIONS = session.generations();
}

EvolutionarySystem::~EvolutionarySystem() {}

void EvolutionarySystem::evolve(const unsigned int epoch) {
    population.populate();
    for (unsigned int generation = 0; generation < GENERATIONS; generation++) {
        evaluator.evaluatePopulation(population);

        statistics.record(population, epoch, generation);

        /*if (population.bestIndividual()->getRelevance().getFitness().isIdeal())
            break;*/

        vector<Individual *> *parents = breeder.breedPopulation(population, epoch);
        replayer.replay(population, *parents);

        for (auto ind : *parents) {
            delete ind;
        }
        delete parents;
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, GENERATIONS);
}


void EvolutionarySystem::run() {
    for (unsigned int epoch = 0; epoch < EPOCHS; epoch++) {
        cout << "Starting epoch " << epoch << "..." << endl;
        for (unsigned int episode = 0; episode < EPISODES; episode++) {
            if (episode % 250 == 0)
                cout << "Epoch " << epoch << ": " << EPISODES - episode << " episodes left." << endl;
            evolve(epoch);
        }
        cout << "Finished epoch " << epoch << "." << endl;
    }
}

Statistics EvolutionarySystem::getStatistics() {
    return statistics;
}