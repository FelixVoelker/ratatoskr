#include "RandomBitVectorBuilder.h"

RandomBitVectorBuilder::RandomBitVectorBuilder(const common::Configuration &configuration, VectorIndividual *prototype)
        : Builder(configuration, prototype) {}

void RandomBitVectorBuilder::initialize(Individual &individual, Thread &thread) const {
    std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();
    for (auto &k : chromosome) {
        k = thread.random.sampleIntFromUniformDistribution(2);
    }
}
