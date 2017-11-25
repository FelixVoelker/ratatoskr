#include "TaskWrapper.h"

TaskWrapper::TaskWrapper(unsigned int popsize) : Problem(popsize) {}

void TaskWrapper::eval(Individual &individual) const {
    this->get_override("eval")(boost::ref(individual));
}

TaskWrapper* TaskWrapper::clone() const {
    this->get_override("clone");
}