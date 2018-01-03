#include "Problem.h"

Problem::Problem(const unsigned int popsize) {
    this->popsize = popsize;
}

Problem::Problem(const Problem &obj) {
    this->popsize = obj.popsize;
}


unsigned int Problem::getPopsize() const {
    return popsize;
}

void Problem::setPopsize(const unsigned int popsize) {
    this->popsize = popsize;
}