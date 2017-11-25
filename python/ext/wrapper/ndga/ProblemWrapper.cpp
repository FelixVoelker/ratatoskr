#include "ProblemWrapper.h"

TaskWrapper::TaskWrapper(unsigned int popsize, unsigned int genes) : NDGAProblem(popsize, genes) {
}

void TaskWrapper::evaluate(Individual &individual) const {
    this->get_override("evaluate")(boost::ref(individual));
}