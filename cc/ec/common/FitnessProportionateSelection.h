#ifndef NDEC_FITNESSPROPORTIONATESELECTION_H
#define NDEC_FITNESSPROPORTIONATESELECTION_H


#include "../../../core/variation/SelectionOperator.h"

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
    explicit FitnessProportionateSelection(const Session &session);

    /**
     * Selects an individual according to its index that is sampled from a fitness dependent probability distribution.
     * @param pop Current state of the evolutionary system's population.
     */
    vector<Individual *> select(const vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const override;

};


#endif //NDEC_FITNESSPROPORTIONATESELECTION_H
