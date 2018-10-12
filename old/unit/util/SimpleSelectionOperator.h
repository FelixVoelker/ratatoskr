#ifndef RATATOSKR_SIMPLESELECTIONOPERATOR_H
#define RATATOSKR_SIMPLESELECTIONOPERATOR_H


#include "../../../core/variation/SelectionOperator.h"

/**
 * A simple instance of SelectionOperator to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleSelectionOperator : public SelectionOperator {

public:
    explicit SimpleSelectionOperator(const core::Configuration &configuration);

    Individual * select(std::vector<Individual *> &parents, Thread &thread) const override;

    SimpleSelectionOperator * clone() const override;

protected:
    SimpleSelectionOperator(const SimpleSelectionOperator &obj) = default;

};


#endif //RATATOSKR_SIMPLESELECTIONOPERATOR_H
