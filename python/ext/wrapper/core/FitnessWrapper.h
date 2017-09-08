#ifndef NDEC_FITNESSWRAPPER_H
#define NDEC_FITNESSWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Fitness.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class FitnessWrapper : public Fitness, public wrapper<Fitness> {

public:
    explicit FitnessWrapper(boost::shared_ptr<Session> session);

    bool isIdeal() override;

    bool operator<(Fitness &other) override;
    bool operator<=(Fitness &other) override;
    bool operator>(Fitness &other) override;
    bool operator>=(Fitness &other) override;
    bool operator==(Fitness &other) override;

    Fitness * clone() const override;

};


#endif //NDEC_FITNESSWRAPPER_H
