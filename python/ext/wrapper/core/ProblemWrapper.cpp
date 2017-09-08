#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize) : Problem(popsize) {}

void ProblemWrapper::evaluate(Individual &individual) const {
    this->get_override("evaluate")(boost::ref(individual));
}