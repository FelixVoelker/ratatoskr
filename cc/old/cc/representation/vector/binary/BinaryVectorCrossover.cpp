#include "BinaryVectorCrossover.h"
#include "../Vector.h"

void BinaryVectorCrossover::recombine(std::vector<Genotype *> genotypes, Thread &thread) {
    if (thread.random.sample() < crossoverrate) {
        auto chromosome1 = dynamic_cast<Vector *>(genotypes.at(0))->getChromosome();
        auto chromosome2 = dynamic_cast<Vector *>(genotypes.at(1))->getChromosome();

        auto genes = static_cast<unsigned int>(chromosome1.size());
        unsigned int xover_point = thread.random.sampleIntFromUniformDistribution(genes);
        for (unsigned int k = xover_point + 1; k < genes; k++) {
            float gene = chromosome1.at(k);
            chromosome1.at(k) = chromosome2.at(k);
            chromosome2.at(k) = gene;
        }

        genotypes.at(0)->evaluated = false;
        genotypes.at(1)->evaluated = false;
    }
}

BinaryVectorCrossover* BinaryVectorCrossover::clone() const {
    return new BinaryVectorCrossover(*this);
}

BinaryVectorCrossover::BinaryVectorCrossover(const BinaryVectorCrossover &obj) : RecombinationOperator(obj) {
    this->crossoverrate = obj.crossoverrate;
}