#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize) : Problem(popsize) {}

void ProblemWrapper::evaluate(Individual &individual) {
    this->get_override("evaluate")(boost::ref(individual));
}