#ifndef NDEC_SELECTIONOPERATOR_H
#define NDEC_SELECTIONOPERATOR_H


#include "VariationSource.h"

/**
 * The blueprint class for selection operators in NDEC. These operators form the lowest layer of
 * the variation pipeline and simply select individuals from the current population
 * of the evolutionary system. Accordingly each selection operator may not have any
 * previous sources.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   31.7.2017
 */
class SelectionOperator : public VariationSource {

protected:
    unsigned long expectedSources();

public:
    explicit SelectionOperator(Session &session);

    /**
     * Selects an individual according to the operator's strategy.
     * @param pop Current state of the evolutionary system's population.
     */
    virtual vector<Individual *> select(Population &pop, Randomizer &random) = 0;

    /**
     * Performs the selection operation on the current population and clones the selected individuals afterwards.
     */
    vector<Individual *> perform(Population &pop, vector<Individual *> parents, Randomizer &random) override;

};


#endif //NDEC_SELECTIONOPERATOR_H