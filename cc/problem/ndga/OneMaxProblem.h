#ifndef NDEC_ONEMAXPROBLEM_H
#define NDEC_ONEMAXPROBLEM_H

#include "../../common/Problem.h"


class OneMaxProblem : public NDGAProblem {

public:
    OneMaxProblem(unsigned int pop_size, unsigned int genes);

    void evaluate(Individual &individual) const /*override*/;

};


#endif //NDEC_ONEMAXPROBLEM_H
