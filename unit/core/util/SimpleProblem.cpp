#include "SimpleProblem.h"

SimpleProblem::SimpleProblem(unsigned int popsize) : Problem(popsize) {}

void SimpleProblem::eval(Individual &individual, Thread &thread) const {
    individual.getFitness().setFitness(1);
}