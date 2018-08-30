#ifndef RATATOSKR_RECOMBINATIONOPERATOR_H
#define RATATOSKR_RECOMBINATIONOPERATOR_H


#include <vector>
#include "Genotype.h"
#include "VariationOperator.h"
#include "../util/Thread.h"

/**
 * @author  FelixVoelker
 * @version 0.1.1
 * @since   13.7.2018
 */
class RecombinationOperator : public VariationOperator {

public:
    virtual void recombine(std::vector<Genotype *> genotypes, Thread &thread) = 0;

};


#endif //RATATOSKR_RECOMBINATIONOPERATOR_H
