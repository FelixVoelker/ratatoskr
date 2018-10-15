#include "RandomBitInitialization.h"
#include "BitString.h"

void RandomBitInitialization::operator()(Genotype &genotype, Thread &thread) const {
    std::vector<bool> chromosome = dynamic_cast<BitString &>(genotype).getChromosome();
    for (auto gene : chromosome) {
        gene = thread.random.sampleIntFromUniformDistribution(2);
    }
}

InitializationOperator* RandomBitInitialization::clone() const {
    return new RandomBitInitialization(*this);
}