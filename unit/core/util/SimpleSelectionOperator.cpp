#include "SimpleSelectionOperator.h"

SimpleSelectionOperator::SimpleSelectionOperator(Session &session) : SelectionOperator(session) {}

Individual* SimpleSelectionOperator::select(std::vector<Individual *> &parents, Thread &thread) const {
    return parents.at(0);
}
