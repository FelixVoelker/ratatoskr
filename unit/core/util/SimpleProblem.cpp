#include "SimpleProblem.h"

SimpleProblem::SimpleProblem(unsigned int popsize) : Problem(popsize) {}

//void SimpleProblem::eval(Individual &individual) const {
////    individual.getFitness().setFitness(1);
//}

SimpleProblem* SimpleProblem::clone() const {
    return new SimpleProblem(*this);
}