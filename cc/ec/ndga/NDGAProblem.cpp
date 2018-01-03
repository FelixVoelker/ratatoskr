#include "NDGAProblem.h"

NDGAProblem::NDGAProblem(const unsigned int popsize, const unsigned int genes) : Problem(popsize) {
    this->genes = genes;
}

NDGAProblem::NDGAProblem(const NDGAProblem &obj) : Problem(obj) {
    this->genes = genes;
}

unsigned int NDGAProblem::getGenes() {
    return genes;
}

void NDGAProblem::setGenes(unsigned int genes) {
    this->genes = genes;
}