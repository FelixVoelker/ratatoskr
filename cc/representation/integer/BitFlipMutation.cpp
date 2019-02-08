#include "BitFlipMutation.h"
#include "IntegerVector.h"

void BitFlipMutation::operator()(Genotype &genotype, Thread &thread) const {
    for (auto gene : dynamic_cast<IntegerVector &>(genotype).getChromosome()) {
        if (thread.random.random() < mutationrate) {
            gene = 1 - gene;
            genotype.evaluated = false;
        }
    }
}
}