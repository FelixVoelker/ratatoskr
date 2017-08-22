#include "NDGAProblem.h"

NDGAProblem::NDGAProblem(unsigned int popsize, unsigned int genes) : Problem(popsize) {
    this->genes = genes;
}