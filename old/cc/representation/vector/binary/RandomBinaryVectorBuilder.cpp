#include "RandomBinaryVectorBuilder.h"

RandomBinaryVectorBuilder::RandomBinaryVectorBuilder() = default;

void RandomBinaryVectorBuilder::build(Genotype &genotype, Thread &thread) const {
    std::vector<float> &chromosome = dynamic_cast<Vector &>(genotype).getChromosome();
    for (auto &k : chromosome) {
        k = thread.random.sampleIntFromUniformDistribution(2);
    }
}

Builder * RandomBinaryVectorBuilder::clone() const {
    return new RandomBinaryVectorBuilder(*this);
}


