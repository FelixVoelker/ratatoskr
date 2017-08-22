#include "BitVectorCrossover.h"
#include "BitVectorIndividual.h"
#include "NDGASession.h"

unsigned long BitVectorCrossover::expectedSources() { return 2; }

BitVectorCrossover::BitVectorCrossover(Session &session)
        : BreedingOperator(session) {
    prob = dynamic_cast<NDGASession &>(session).xover_rate;
    genes = dynamic_cast<NDGAProblem &>(session.problem()).genes;
}

vector<Individual *> BitVectorCrossover::breed(vector<Individual *> parents, Randomizer &random) {
    auto parent1 = dynamic_cast<BitVectorIndividual *>(parents.at(0));
    auto parent2 = dynamic_cast<BitVectorIndividual *>(parents.at(1));

    auto offspring1 = parent1->clone();
    auto offspring2 = parent2->clone();

    if (random.random() < prob) {
        int crossover_point = random.randomInt(genes);

        for (int k = crossover_point + 1; k < genes; k++) {
            offspring1->getChromosome().at(k) = parent2->getChromosome().at(k);
            offspring2->getChromosome().at(k) = parent1->getChromosome().at(k);
        }

        offspring1->evaluated = false;
        offspring2->evaluated = false;
    }

    vector<Individual *> offsprings(2);
    offsprings.at(0) = offspring1;
    offsprings.at(1) = offspring2;
    return offsprings;
}