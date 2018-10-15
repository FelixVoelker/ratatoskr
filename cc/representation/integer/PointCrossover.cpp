#include "PointCrossover.h"

PointCrossover::PointCrossover(unsigned int numPoints) : RecombinationOperator() {
    this->numPoints = numPoints;
}

void PointCrossover::operator()(Genotype &genotype1, Genotype &genotype2, Thread &thread) const {}

PointCrossover::PointCrossover(const PointCrossover &obj) {
    this->numPoints = obj.numPoints;
}