#include "PointCrossover.h"
#include "IntegerVector.h"

PointCrossover::PointCrossover(unsigned int numPoints) : RecombinationOperator() {
    this->numPoints = numPoints;
}

void PointCrossover::operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const {
    auto chromosome1 = dynamic_cast<IntegerVector>(genotype1).getChromosome();
    auto chromosome2 = dynamic_cast<IntegerVector>(genotype2).getChromosome();

    unsigned int genes = chromosome1.size();
    std::priority_queue<unsigned int, std::greater<unsigned int>> xoverPoints;
    for (auto idx : thread.random.sample(1, genes - 1, k = numPoints)) {
        xoverPoints.push(idx);
    }

    unsigned int pointer = 0;
    while (!xoverPoints.empty()) {
        for (unsigned int &k = pointer; k < xoverPoints.pop(); k++) {

        }
    }
}

PointCrossover::PointCrossover(const PointCrossover &obj) {
    this->numPoints = obj.numPoints;
}