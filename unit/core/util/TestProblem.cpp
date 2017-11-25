#include "TestProblem.h"

TestProblem::TestProblem(unsigned int popsize) : Problem(popsize) {}

void TestProblem::eval(Individual &individual) const {
    individual.getRelevance().getFitness().setFitness(1);
}