#include "MutationOperator.h"

unsigned int MutationOperator::numParents() const {
	return 1;
}

unsigned int MutationOperator::numOffspring() const {
	return 1;
}

std::vector<Genotype *> MutationOperator::vary(std::vector<Genotype *> &genotypes, Thread &thread) const {
	this->operator()(*genotypes.at(0), thread);
	return genotypes;
}
