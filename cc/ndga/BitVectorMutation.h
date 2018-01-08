#ifndef NDEC_BITVECTORMUTATION_H
#define NDEC_BITVECTORMUTATION_H


#include "../../core/variation/BreedingOperator.h"
#include "NDGASession.h"

/**
 * TODO: Comments
 * Represents the Bit Flip Mutation as described in "Melanie Mitchell: An Introduction to Genetic Algorithms (1996)."
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   31.7.2017
 */
class BitVectorMutation : public BreedingOperator {

protected:
    int genes;

protected:
    unsigned long expectedSources() const override;

public:
    explicit BitVectorMutation(const NDGASession &session);

    /**
     * A bit flip is performed on each locus of each parent's chromosome with a probability pm.
     * @param parents Parent individuals for the mutation.
     */
    vector<Individual *> & breed(vector<Individual *> &parents, Randomizer &random) const override;

};


#endif //NDEC_BITVECTORMUTATION_H
