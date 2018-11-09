#include "UniformCrossover.h"

void UniformCrossover::operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const {
    //auto chromosome1 = dynamic_cast<B>
    //for (unsigned int k = 0; k < dynamic_cast<>genotype1)
    //if (thread.random.sample() < p) {

    //}
}

UniformCrossover::UniformCrossover(const UniformCrossover &obj) {
    this->p = obj.p;
}