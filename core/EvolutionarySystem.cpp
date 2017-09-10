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

void EvolutionarySystem::evolve(const unsigned int epoch) {
    population.initialize();
    for (unsigned int generation = 0; generation < GENERATIONS; generation++) {
        evaluator.evaluatePopulation(population);

        statistics.record(population, epoch, generation);

        if (population.bestIndividual()->getRelevance().getFitness().isIdeal())
            break;

        vector<Individual *> *offsprings = breeder.breedPopulation(population, epoch);
        replayer.replay(population, *offsprings);
        population.changeGeneration(offsprings);
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, GENERATIONS);
    population.finalize();
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