#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize, unsigned int genes) : NDGAProblem(popsize, genes) {
}

void ProblemWrapper::evaluate(Individual &individual) const {
    this->get_override("evaluate")(boost::ref(individual));
}