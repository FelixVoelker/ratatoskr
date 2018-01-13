#ifndef RATATOSKR_RANDOMBITVECTORBUILDER_H
#define RATATOSKR_RANDOMBITVECTORBUILDER_H


#include "../../core/initialization/Builder.h"
#include "../common/VectorIndividual.h"

/**
 * A bit vector builder for Neuro-Dynamic Genetic Algorithms (NDGAs) that samples the genes of a vector individual's
 * chromosome randomly.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.1.2018
 */
class RandomBitVectorBuilder : public Builder {

public:
    explicit RandomBitVectorBuilder(const common::Configuration &configuration, VectorIndividual *prototype);

protected:
    /**
     * Samples each gene of the chromosome from a uniform discrete distribution U~(0,1).
     * @param individual The individual to be initialized.
     * @param thread     The initializing thread.
     */
    void initialize(Individual &individual, Thread &thread) const override;

};


#endif //RATATOSKR_RANDOMBITVECTORBUILDER_H
