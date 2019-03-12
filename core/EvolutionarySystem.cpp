#include "EvolutionarySystem.h"

EvolutionarySystem::EvolutionarySystem(Representation &representation) : representation(representation) {}

void EvolutionarySystem::initialize(Population &pop, std::vector<Thread> &threads) {
    auto &individuals = pop.getIndividuals();

    unsigned long onset = 0;
    unsigned long offset = individuals.size() / threads.size();

    std::vector<std::thread> workers;
    for (auto &thread : threads) {
        thread.task = std::thread([this, &individuals, &thread, onset, offset](){
            InitializationOperator &init = this.representation.getInitializationOperator();
            for (unsigned int k = 0; k < offset; k++) {
                init(individuals.at(k).getGenotype(), thread);
            }
        });
        onset += offset;
    }
    for (auto &thread : threads) {
        thread.task.join();
    }
}

void EvolutionarySystem::evaluate(Population &pop, std::vector<Thread> &threads) {}

void EvolutionarySystem::vary(Population &pop, std::vector<Thread> &threads) {}

/*
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
}*/