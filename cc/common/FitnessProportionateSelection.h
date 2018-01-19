#ifndef RATATOSKR_FITNESSPROPORTIONATESELECTION_H
#define RATATOSKR_FITNESSPROPORTIONATESELECTION_H


#include "../../core/variation/SelectionOperator.h"
#include "Configuration.h"

/**
 * A roulette wheel selection operator as commonly used in Neuro-Dynamic Evolutionary Algorithms (NDEAs).
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class FitnessProportionateSelection : public SelectionOperator {

public:
    explicit FitnessProportionateSelection(const common::Configuration &configuration);

    /**
     * Samples an individual based on a relevance dependent probability distribution whose fraction is determined by
     * an alignment strategy over the number of epochs, i.e. fraction = current epoch / total epochs.
     */
    Individual * select(std::vector<Individual *> &parents, Thread &thread) const override;

protected:
    unsigned int epochs;

};


#endif //RATATOSKR_FITNESSPROPORTIONATESELECTION_H
