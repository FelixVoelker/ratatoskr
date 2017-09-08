#ifndef NDEC_INDIVIDUALWRAPPER_H
#define NDEC_INDIVIDUALWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Individual.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class IndividualWrapper : public Individual, public wrapper<Individual> {

public:
    explicit IndividualWrapper(boost::shared_ptr<Session> session);

    string toString() override;

    Individual * clone() const override;

};


#endif //NDEC_INDIVIDUALWRAPPER_H
