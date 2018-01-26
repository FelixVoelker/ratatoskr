#include <iostream>
#include "EvolutionarySystem.h"

EvolutionarySystem::EvolutionarySystem(const core::Configuration &configuration,
                                       Builder &builder,
                                       const std::function<void(Individual &, Thread &)> &eval,
                                       EvolutionaryNetwork &network,
                                       BreedingOperator &variation_tree)
        : network(network.clone()),
          population(Population(configuration)),
          initializer(Initializer(configuration, builder, epoch)),
          evaluator(Evaluator(configuration, eval, *this->network, epoch)),
          breeder(Breeder(configuration, variation_tree, epoch)),
          statistics(Statistics(configuration)),
          replayer(Replayer(configuration, *this->network))
{
    complete = configuration.getEvolutionarySystemConfiguration().complete;
    epochs = configuration.getEvolutionarySystemConfiguration().epochs;
    episodes = configuration.getEvolutionarySystemConfiguration().episodes;
    generations = configuration.getEvolutionarySystemConfiguration().generations;
}

EvolutionarySystem::~EvolutionarySystem() {
    delete network;
}

void EvolutionarySystem::run() {
    epoch = 0;
    for (unsigned int &k = epoch; k < epochs; k++) {
        std::cout << "Starting epoch " << epoch << "..." << std::endl;
        for (unsigned int episode = 0; episode < episodes; episode++) {
            if (episode % 250 == 0) {
                std::cout << "Epoch " << epoch << ": " << episodes - episode << " episodes left." << std::endl;
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
            if (population.bestIndividual()->getRelevance().isIdeal()) {
                break;
            }
        }

        std::vector<Individual *> *offsprings = breeder.breedPopulation(population);
        replayer.replay(population, *offsprings);
        population.exterminate();
        population.setIndividuals(*offsprings);
        delete offsprings;
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, generations);
    population.exterminate();
}