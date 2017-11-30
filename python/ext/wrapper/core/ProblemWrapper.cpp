#include "ProblemWrapper.h"

ProblemWrapper::ProblemWrapper(unsigned int popsize) : Problem(popsize) {}

//void ProblemWrapper::eval(Individual &individual) const {
//    this->get_override("eval")(boost::ref(individual));
//}

ProblemWrapper* ProblemWrapper::clone() const {
    this->get_override("clone");
}