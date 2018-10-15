#include <iostream>
#include "EvolutionarySystem.h"
#include "../cc/ndga/EvaluationFunctions.h"

EvolutionarySystem::EvolutionarySystem(
                                       Builder &builder,
                                       const EvaluationFunction &eval,
                                       EvolutionaryNetwork &network,
                                       BreedingOperator &variation_tree,
                                       ReplayMemory &memory)
        : network(network.clone()),
          memory(memory.clone()),
          population(Population(configuration)),
          initializer(Initializer(configuration, builder, epoch)),
          evaluator(Evaluator(configuration, eval, *this->network)),
          breeder(Breeder(configuration, *this->memory, variation_tree)),
          replayer(Replayer(configuration, *this->network, *this->memory))
{
    complete = configuration.getEvolutionarySystemConfiguration().complete;
    epochs = configuration.getEvolutionarySystemConfiguration().epochs;
    episodes = configuration.getEvolutionarySystemConfiguration().episodes;
    generations = configuration.getEvolutionarySystemConfiguration().generations;
}

EvolutionarySystem::~EvolutionarySystem() {
    delete network;
}

void EvolutionarySystem::evolutionaryCycle(Population &population) () {
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
        replayer.replay();
        population.exterminate();
        population.setIndividuals(*offsprings);
        delete offsprings;
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, epoch, generations);
    population.exterminate();
}

Genotype & EvolutionarySystem::getGenotype() const {
    return genotype;
}