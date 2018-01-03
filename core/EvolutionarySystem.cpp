#include <iostream>
#include "EvolutionarySystem.h"

EvolutionarySystem::EvolutionarySystem(Session &session)
        : population(Population(session)),
          initializer(Initializer(session, epoch)),
          evaluator(Evaluator(session, epoch)),
          breeder(Breeder(session, epoch)),
          statistics(Statistics(session)),
          replayer(Replayer(session))
{
    complete = session.isComplete();
    epochs = session.getEpochs();
    episodes = session.getEpisodes();
    generations = session.getGenerations();
}

void EvolutionarySystem::run() {
    epoch = 0;
    for (unsigned int &k = epoch; k < epochs; k++) {
        std::cout << "Starting epoch " << epoch << "..." << std::endl;
        for (unsigned int episode = 0; episode < episodes; episode++) {
            if (episode % 250 == 0) {
                std::cout << "Epoch " << epoch << ": " << episodes - episode << " getEpisodes left." << std::endl;
            }
            evolve();
        }
        std::cout << "Finished epoch " << epoch << "." << std::endl;
    }
}

Statistics & EvolutionarySystem::getStatistics() {
    return statistics;
}

void EvolutionarySystem::evolve() {
    initializer.initializePopulation(population);
    for (unsigned int generation = 0; generation < generations; generation++) {
        evaluator.evaluatePopulation(population);
        statistics.record(population, epoch, generation);

        if (!complete) {
            if (population.bestIndividual()->getFitness().isIdeal()) {
                break;
            }
        }

        std::vector<Individual *> *offsprings = breeder.breedPopulation(population);
        replayer.replay(population, *offsprings);
        population.setIndividuals(*offsprings);
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, generations);
    population.exterminate();
}