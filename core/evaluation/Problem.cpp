#include "Problem.h"

Problem::Problem(unsigned int popsize) {
    this->_popsize = popsize;
}

unsigned int Problem::popsize() {
    return _popsize;
}

void Problem::popsize(unsigned int popsize) {
    this->_popsize = popsize;
}