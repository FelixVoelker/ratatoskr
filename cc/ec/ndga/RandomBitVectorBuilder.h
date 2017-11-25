#ifndef NDEC_RANDOMBITVECTORBUILDER_H
#define NDEC_RANDOMBITVECTORBUILDER_H


#include <random>
#include "../../../core/initialization/Builder.h"
#include "NDGASession.h"
#include "../../../core/util/Randomizer.h"

/**
 * TODO: Comments
 * A bit vector builder that uses a uniform random distribution to sample the genes of a BitVectorIndividual's
 * chromosome.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   5.7.2017
 */
class RandomBitVectorBuilder : public Builder {

private:
    Randomizer *random;

    /**
     * Samples each gene of the chromosome from a uniform distribution over {0,1}.
     * @param ind The individual to be initialized.
     */
    void initialize(Individual &ind) const override;

public:
    explicit RandomBitVectorBuilder(const NDGASession &session);
    ~RandomBitVectorBuilder();

};


#endif //NDEC_RANDOMBUILDER_H
