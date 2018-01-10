#include "BitVectorCrossover.h"
#include "../common/VectorIndividual.h"

BitVectorCrossover::BitVectorCrossover(common::Configuration &configuration) : BreedingOperator(configuration) {
    this->pc = configuration.getCrossoverConfiguration().xover_rate;
}

unsigned long BitVectorCrossover::expectedSources() const { return 2; }

std::vector<Individual *> & BitVectorCrossover::breed(std::vector<Individual *> &parents, Thread &thread) const {
    auto *parent1 = dynamic_cast<VectorIndividual *>(parents.at(0));
    auto *parent2 = dynamic_cast<VectorIndividual *>(parents.at(1));

    if (thread.random.sample() < pc) {
        auto genes = static_cast<unsigned int>(parent1->getChromosome().size());
        unsigned int xover_point = thread.random.sampleIntFromUniformDistribution(genes);

        for (unsigned int k = xover_point + 1; k < genes; k++) {
            float gene = parent1->getChromosome().at(k);
            parent1->getChromosome().at(k) = parent2->getChromosome().at(k);
            parent2->getChromosome().at(k) = gene;
        }

        parent1->setEvaluated(false);
        parent2->setEvaluated(false);
    }

    return parents;
}