#ifndef RATATOSKR_RANDOMBITVECTORBUILDER_H
#define RATATOSKR_RANDOMBITVECTORBUILDER_H


#include "../../../../core/representation/Builder.h"
#include "../Vector.h"

/**
 * @todo change comments
 * A bit vector builder for Neuro-Dynamic Genetic Algorithms (NDGAs) that samples the genes of a vector individual's
 * chromosome randomly.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class RandomBinaryVectorBuilder : public Builder {

public:
    RandomBinaryVectorBuilder();

    /**
    * Samples each gene of the chromosome from a uniform discrete distribution U~(0,1).
    * @param individual The individual to be initialized.
    * @param thread     The initializing thread.
    */
    void build(Genotype &genotype, Thread &thread) const override;

    Builder * clone() const override;

protected:
    RandomBinaryVectorBuilder(const RandomBinaryVectorBuilder &obj) = default;

};


#endif //RATATOSKR_RANDOMBITVECTORBUILDER_H
