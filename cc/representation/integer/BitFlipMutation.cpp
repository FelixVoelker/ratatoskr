#include "BitFlipMutation.h"
#include "BitString.h"

void BitFlipMutation::operator()(Genotype &genotype, Thread &thread) const {
    for (auto gene : dynamic_cast<BitString &>(genotype).getChromosome()) {
        if (thread.random.sample() < mutationrate) {
            gene = 1 - gene;
            genotype.evaluated = false;
        }
    }
}
}