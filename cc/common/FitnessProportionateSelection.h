#ifndef NDEC_FITNESSPROPORTIONATESELECTION_H
#define NDEC_FITNESSPROPORTIONATESELECTION_H


#include "../../core/variation/SelectionOperator.h"
#include "Configuration.h"

/**
 * TODO: Comments
 * Represents the roulette wheel selection as commonly used in evolutionary algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   5.8.2017
 */
class FitnessProportionateSelection : public SelectionOperator {

public:
    explicit FitnessProportionateSelection(common::Configuration &session);

    /**
     * Selects an individual according to its index that is sampled from a fitness dependent probability distribution.
     * @param pop Current state of the evolutionary system's population.
     */
    Individual * select(std::vector<Individual *> &parents, Thread &thread) const override;

};


#endif //NDEC_FITNESSPROPORTIONATESELECTION_H
