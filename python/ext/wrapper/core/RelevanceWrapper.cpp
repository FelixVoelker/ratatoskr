#include "RelevanceWrapper.h"

RelevanceWrapper::RelevanceWrapper(boost::shared_ptr<Session> session) : Relevance(*session) {}

float RelevanceWrapper::relevance(int epoch) {
    if (override relevance = this->get_override("relevance")) {
        return relevance(epoch);
    }
    return Relevance::relevance(epoch);
}

float RelevanceWrapper::default_relevance(int epoch) {
    return Relevance::relevance(epoch);
}