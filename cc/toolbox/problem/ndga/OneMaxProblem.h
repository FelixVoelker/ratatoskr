#ifndef NDEC_ONEMAXPROBLEM_H
#define NDEC_ONEMAXPROBLEM_H

#include "../../ec/ndga/NDGAProblem.h"


class OneMaxProblem : public NDGAProblem {

public:
    OneMaxProblem(unsigned int pop_size, unsigned int genes);

    void evaluate(Individual &individual) override;
};


#endif //NDEC_ONEMAXPROBLEM_H
