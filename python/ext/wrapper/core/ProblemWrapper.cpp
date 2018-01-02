#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize) : Problem(popsize) {}

void ProblemWrapper::eval(Individual &individual, Thread &thread) const {
    this->get_override("eval")(individual, thread);
}
