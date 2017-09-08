#include "NDGAProblem.h"

NDGAProblem::NDGAProblem(const unsigned int popsize, const unsigned int genes) : Problem(popsize) {
    this->genes = genes;
}