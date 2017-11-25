#ifndef NDEC_FITNESSWRAPPER_H
#define NDEC_FITNESSWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Fitness.h"

using namespace boost::python;

/**
 * TODO: Comments
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class FitnessWrapper : public Fitness, public wrapper<Fitness> {

public:
    explicit FitnessWrapper(boost::shared_ptr<Session> session);

    bool isIdeal() const override;
    bool default_isIdeal() const;

    bool operator<(const Fitness &other) const override;
    bool default_lt(const Fitness &other) const;
    bool operator<=(const Fitness &other) const override;
    bool default_leq(const Fitness &other) const;
    bool operator>(const Fitness &other) const override;
    bool default_gt(const Fitness &other) const;
    bool operator>=(const Fitness &other) const override;
    bool default_geq(const Fitness &other) const;
    bool operator==(const Fitness &other) const override;
    bool default_eq(const Fitness &other) const;

};


#endif //NDEC_FITNESSWRAPPER_H
