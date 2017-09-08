#include "BitVectorCrossover.h"
#include "BitVectorIndividual.h"

unsigned long BitVectorCrossover::expectedSources() const { return 2; }

BitVectorCrossover::BitVectorCrossover(const NDGASession &session)
        : BreedingOperator(session) {
    prob = session.xover_rate;
    genes = dynamic_cast<const NDGAProblem &>(session.problem()).genes;
}

vector<Individual *> & BitVectorCrossover::breed(vector<Individual *> &parents, Randomizer &random) const {
    auto parent1 = dynamic_cast<BitVectorIndividual *>(parents.at(0));
    auto parent2 = dynamic_cast<BitVectorIndividual *>(parents.at(1));

    if (random.random() < prob) {
        int crossover_point = random.randomInt(genes);

        for (int k = crossover_point + 1; k < genes; k++) {
            unsigned int gene = parent1->getChromosome().at(k);
            parent1->getChromosome().at(k) = parent2->getChromosome().at(k);
            parent2->getChromosome().at(k) = gene;
        }

        parent1->evaluated(false);
        parent2->evaluated(false);
    }

    return parents;
}