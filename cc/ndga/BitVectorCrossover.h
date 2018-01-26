#ifndef RATATOSKR_BITVECTORCROSSOVER_H
#define RATATOSKR_BITVECTORCROSSOVER_H


#include "../../core/variation/BreedingOperator.h"
#include "../common/Configuration.h"

/**
 * The one point crossover breeding operator as described in "Melanie Mitchell: An Introduction to
 * Genetic Algorithms (1996)."
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class BitVectorCrossover : public BreedingOperator {

public:
    explicit BitVectorCrossover(const common::Configuration &configuration);

    BitVectorCrossover * clone() const override;

protected:
    float pc;

    BitVectorCrossover(const BitVectorCrossover &obj);

    unsigned long expectedSources() const override;

    /**
     * Performs a one point crossover of two parents with a probability pc.
     * @param parents Parent individuals to be crossed over.
     * @param thread  The variating thread.
     */
    std::vector<Individual *> & breed(std::vector<Individual *> &parents, Thread &thread) const override;

};


#endif //RATATOSKR_BITVECTORCROSSOVER_H
