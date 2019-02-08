#include "RandomBitInitialization.h"
#include "IntegerVector.h"

void RandomBitInitialization::operator()(Genotype &genotype, Thread &thread) const {
    auto chromosome = dynamic_cast<IntegerVector &>(genotype).getChromosome();
    for (auto gene : chromosome) {
        gene = thread.random.choose(std::vector<unsigned int>({0, 1})).at(0);
    }
}

InitializationOperator* RandomBitInitialization::clone() const {
    return new RandomBitInitialization(*this);
}