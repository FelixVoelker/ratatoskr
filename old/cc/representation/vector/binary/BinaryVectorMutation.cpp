#include "BinaryVectorMutation.h"
#include "../Vector.h"

void BinaryVectorMutation::mutate(Genotype &genotype, Thread &thread) {
    auto chromosome = dynamic_cast<Vector &>(genotype).getChromosome();
    for (float &locus : chromosome) {
        if (thread.random.sample() < mutationrate) {
            locus = 1 - locus;
            genotype.evaluated = false;
        }
    }
}

BinaryVectorMutation * BinaryVectorMutation::clone() const {
    return new BinaryVectorMutation(*this);
}

BinaryVectorMutation::BinaryVectorMutation(const BinaryVectorMutation &obj) : MutationOperator(obj) {
    this->mutationrate = obj.mutationrate;
}

