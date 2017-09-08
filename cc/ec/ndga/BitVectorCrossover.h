#ifndef NDEC_BITVECTORCROSSOVER_H
#define NDEC_BITVECTORCROSSOVER_H


#include "../../../core/variation/BreedingOperator.h"
#include "NDGASession.h"

/**
 * Represents the One Point Crossover as described in "Melanie Mitchell: An Introduction to Genetic Algorithms (1996)."
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   31.7.2017
 */
class BitVectorCrossover : public BreedingOperator {

protected:
    int genes;

protected:
    unsigned long expectedSources() const override;

public:
    explicit BitVectorCrossover(const NDGASession &session);

    /**
     * Performs a one point crossover of two parents with a probability pc.
     * @param parents Parent individuals for the crossover.
     */
    vector<Individual *> & breed(vector<Individual *> &parents, Randomizer &random) const override;

};


#endif //NDEC_BITVECTORCROSSOVER_H
