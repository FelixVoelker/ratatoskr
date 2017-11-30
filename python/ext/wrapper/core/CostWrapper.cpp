#include "CostWrapper.h"

RelevanceWrapper::RelevanceWrapper(boost::shared_ptr<Session> session) : Cost(*session) {}

float RelevanceWrapper::relevance(int epoch) {
    if (override relevance = this->get_override("setCost")) {
        return relevance(epoch);
    }
    return Cost::relevance(epoch);
}

float RelevanceWrapper::default_relevance(int epoch) {
    return Cost::relevance(epoch);
}