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

void EvolutionarySystem::evolve(int epoch) {
    population.populate();
    for (unsigned int generation = 0; generation < GENERATIONS; generation++) {
        evaluator.evaluatePopulation(population);

        statistics.record(population, epoch, generation);

        if (population.bestIndividual()->getRelevance().getFitness().isIdeal())
            break;

        vector<Individual *> &parents = breeder.breedPopulation(population, epoch);
        replayer.replay(population, parents);
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, GENERATIONS);
}


void EvolutionarySystem::run() {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int episode = 0; episode < EPISODES; episode++) {
            evolve(epoch);
        }
    }
}

Statistics EvolutionarySystem::getStatistics() {
    return statistics;
}