#include "SelectionOperatorWrapper.h"

SelectionOperatorWrapper::SelectionOperatorWrapper(Configuration &configuration) : SelectionOperator(configuration) {}

Individual* SelectionOperatorWrapper::select(std::vector<Individual *> &parents, Thread &thread) const {
    return this->get_override("select")(parents, thread);
}