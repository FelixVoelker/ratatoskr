#include "RecombinationOperator.h"

unsigned int RecombinationOperator::numParents() const {
    return 2;
}

unsigned int RecombinationOperator::numOffspring() const {
    return 2;
}

std::vector<Genotype *> RecombinationOperator::vary(std::vector<Genotype *> &genotypes, Thread &thread) const {
    this->operator()(*genotypes.at(0), *genotypes.at(1), thread);
    return genotypes;
}