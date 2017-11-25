#include "NDGAProblem.h"

NDGAProblem::NDGAProblem(NDGAProblem &obj) : Problem(obj) {
    this->genes = obj.genes;
}

NDGAProblem::NDGAProblem(const unsigned int popsize, const unsigned int genes) : Problem(popsize) {
    this->genes = genes;
}

NDGAProblem* NDGAProblem::clone() {
    return new NDGAProblem(*this);
}