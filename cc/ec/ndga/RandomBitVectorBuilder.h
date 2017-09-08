#ifndef NDEC_RANDOMBITVECTORBUILDER_H
#define NDEC_RANDOMBITVECTORBUILDER_H


#include <random>
#include "../../../core/initialization/Builder.h"
#include "NDGASession.h"

/**
 * A bit vector builder that uses a uniform random distribution to sample the genes of a BitVectorIndividual's
 * chromosome.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   5.7.2017
 */
class RandomBitVectorBuilder : public Builder {

private:
    /**
     * Samples each gene of the chromosome from a uniform distribution over {0,1}.
     * @param ind The individual to be initialized.
     */
    void initialize(Individual &ind) const override;

public:
    explicit RandomBitVectorBuilder(const NDGASession &session);

};


#endif //NDEC_RANDOMBUILDER_H
