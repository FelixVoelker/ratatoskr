#include "Problem.h"

Problem::Problem(const unsigned int popsize) {
    this->_popsize = popsize;
}

unsigned int Problem::popsize() const {
    return _popsize;
}

void Problem::popsize(const unsigned int popsize) {
    this->_popsize = popsize;
}