#include "RelevanceWrapper.h"

RelevanceWrapper::RelevanceWrapper(boost::shared_ptr<Session> session) : Relevance(*session) {}

float RelevanceWrapper::relevance(int epoch) {
    return this->get_override("relevance")(epoch);
}

Relevance* RelevanceWrapper::clone() {
    return this->get_override("clone")();
}