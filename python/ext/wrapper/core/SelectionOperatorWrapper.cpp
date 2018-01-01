#include "SelectionOperatorWrapper.h"

SelectionOperatorWrapper::SelectionOperatorWrapper(boost::shared_ptr<Session> session) : SelectionOperator(*session) {}

Individual* SelectionOperatorWrapper::select(std::vector<Individual *> &parents, Thread &thread) const {
    return this->get_override("select")(parents, thread);
}