#include "RecombinationOperator.h"

unsigned int RecombinationOperator::numParents() const {
    return 2;
}

unsigned int RecombinationOperator::numOffspring() const {
    return 2;
}

std::vector<Genotype *> RecombinationOperator::operator()(std::vector<Genotype *> &parents, Thread &thread) const {
    this->operator()(parents.at(0), parents.at(1), thread);
    return parents;
}