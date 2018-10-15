#include "MutationOperator.h"

unsigned int MutationOperator::numParents() const {
	return 1;
}

unsigned int MutationOperator::numOffspring() const {
	return 1;
}

std::vector<Genotype *> MutationOperator::operator()(std::vector<Genotype *> &parents, Thread &thread) const {
	this->operator()(parents.at(0), thread);
	return parents;
}
