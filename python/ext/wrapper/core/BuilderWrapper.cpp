#include "BuilderWrapper.h"

BuilderWrapper::BuilderWrapper(boost::shared_ptr<Session> session) : Builder(*session) {}

void BuilderWrapper::initialize(Individual &ind) const {
    this->get_override("initialize")();
}