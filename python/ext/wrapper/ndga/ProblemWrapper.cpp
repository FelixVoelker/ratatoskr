#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize, unsigned int genes) : NDGAProblem(popsize, genes) {
}

void ProblemWrapper::evaluate(Individual &individual) {
    this->get_override("evaluate")(boost::ref(individual));
}