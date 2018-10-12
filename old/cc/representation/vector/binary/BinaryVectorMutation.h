#ifndef RATATOSKR_BINARYVECTORMUTATION_H
#define RATATOSKR_BINARYVECTORMUTATION_H


#include "../../../../../core/representation/MutationOperator.h"

/**
 * @todo: change comment
 * The bit flip mutation breeding operator as described in "Melanie Mitchell: An Introduction to
 * Genetic Algorithms (1996)."
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   25.1.2018
 */
class BinaryVectorMutation : public MutationOperator {

public:
    float mutationrate = 0.1;

    BinaryVectorMutation() = default;

    /**
     * Performs a bit flip on each locus of the parents' chromosomes with a probability pm.
     * @param parents Parent individuals to be mutated.
     * @param thread  The variating thread.
     */
    void mutate(Genotype &genotype, Thread &thread) override;

    BinaryVectorMutation * clone() const override;

protected:
    BinaryVectorMutation(const BinaryVectorMutation &obj);

};


#endif //RATATOSKR_BINARYVECTORMUTATION_H
