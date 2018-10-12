#ifndef RATATOSKR_BITVECTORCROSSOVER_H
#define RATATOSKR_BITVECTORCROSSOVER_H


#include "../../../../../core/representation/RecombinationOperator.h"

/**
 * @todo change comment
 * The one point crossover breeding operator as described in "Melanie Mitchell: An Introduction to
 * Genetic Algorithms (1996)."
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   14.7.2018
 */
class BinaryVectorCrossover : public RecombinationOperator {

public:
    float crossoverrate = 0.8;

    BinaryVectorCrossover() = default;

    /**
    * Performs a one point crossover of two parents with a probability pc.
    * @param parents Parent individuals to be crossed over.
    * @param thread  The variating thread.
    */
    void recombine(std::vector<Genotype *> genotypes, Thread &thread) override;

    BinaryVectorCrossover * clone() const override;

protected:
    BinaryVectorCrossover(const BinaryVectorCrossover &obj);

};


#endif //RATATOSKR_BITVECTORCROSSOVER_H
