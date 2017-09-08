#ifndef NDEC_RELEVANCEWRAPPER_H
#define NDEC_RELEVANCEWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Relevance.h"

using namespace boost::python;


/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.9.2017
 */
class RelevanceWrapper : public Relevance, public wrapper<Relevance> {

public:
    explicit RelevanceWrapper(boost::shared_ptr<Session> session);

    float relevance(int epoch) override;

    Relevance * clone() const override;
};


#endif //NDEC_RELEVANCEWRAPPER_H
