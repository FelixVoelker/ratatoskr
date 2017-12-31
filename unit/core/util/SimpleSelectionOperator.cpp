#include "SimpleSelectionOperator.h"

SimpleSelectionOperator::SimpleSelectionOperator(Session &session) : SelectionOperator(session) {}

Individual* SimpleSelectionOperator::select(std::vector<Individual *> &parents,
                                            unsigned int epoch,
                                            Thread &thread) const {
    return parents.at(0);
}
