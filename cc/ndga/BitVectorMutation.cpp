#include "BitVectorMutation.h"
#include "../common/VectorIndividual.h"
#include <iostream>

BitVectorMutation::BitVectorMutation(const common::Configuration &configuration) : BreedingOperator(configuration) {
    this->pm = configuration.getMutationConfiguration().mutation_rate;
}

unsigned long BitVectorMutation::expectedSources() const { return 1; }

std::vector<Individual *> & BitVectorMutation::breed(std::vector<Individual *> &parents, Thread &thread) const {
    for (auto *parent : parents) {
        auto *p = dynamic_cast<VectorIndividual *>(parent);
        auto genes = p->getChromosome().size();
        for (unsigned int k = 0; k < genes; k++) {
            if (thread.random.sample() < pm) {
                p->getChromosome().at(k) = 1 - p->getChromosome().at(k);
                p->setEvaluated(false);
            }
        }
    }

    return parents;
}