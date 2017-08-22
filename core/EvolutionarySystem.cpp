#include <iostream>
#include "EvolutionarySystem.h"
#include "../cc/toolbox/ec/common/RawFitness.h"

EvolutionarySystem::EvolutionarySystem(Session &session)
        : population(Population(session)),
          evaluator(Evaluator(session)),
          breeder(Breeder(session)),
          statistics(Statistics(session)) {
    GENERATIONS = session.generations;
}

EvolutionarySystem::~EvolutionarySystem() {}


void EvolutionarySystem::run() {
    population.populate();
    for (unsigned int generation = 0; generation < GENERATIONS; generation++) {
        evaluator.evaluatePopulation(population);

        statistics.record(population, generation);

        /*if (population.bestIndividual()->getFitness().isIdeal())
            break;*/
        breeder.breedPopulation(population);
    }
    evaluator.evaluatePopulation(population);
    statistics.record(population, GENERATIONS);
    statistics.print();
}