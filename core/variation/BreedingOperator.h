#ifndef RATATOSKR_BREEDINGOPERATOR_H
#define RATATOSKR_BREEDINGOPERATOR_H


#include "VariationSource.h"

/**
 * The abstract base class for breeding operators in a Neuro-Dynamic Evolutionary Algorithm (NDEA). These operators
 * form the internal nodes of variation trees and generate new offsprings from the breed of their child sources.
 * Accordingly, the root of each variation tree is a breeding operator and each breeding operator needs at least
 * one child.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   1.1.2018
 */
class BreedingOperator : public VariationSource {

public:
    explicit BreedingOperator(const core::Configuration &configuration);

    void setup(std::vector<VariationSource *> &sources) override;

protected:
    /**
     * Breeds new offsprings from given parent individuals according to the operator's strategy.
     * @param parents A list of parent individuals.
     * @param thread  The variating thread.
     */
    virtual std::vector<Individual *> & breed(std::vector<Individual *> &parents, Thread &thread) const = 0;

    std::vector<Individual *> perform(std::vector<Individual *> &parents, Thread &thread) const override;

};


#endif //RATATOSKR_BREEDINGOPERATOR_H
