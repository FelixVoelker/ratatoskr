#include "core_wrapper.h"

struct ProblemWrapper : NDGAProblem, wrapper<NDGAProblem> {

public:
    ProblemWrapper(unsigned int popsize, unsigned int genes) : NDGAProblem(popsize, genes) {}

};
