#ifndef RATATOSKR_FITNESSWRAPPER_H
#define RATATOSKR_FITNESSWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Fitness.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Fitness.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   30.11.2017
 */
class FitnessWrapper : public Fitness, public wrapper<Fitness> {

public:
    explicit FitnessWrapper(Configuration &configuration);

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
    bool operator!=(const Fitness &other) const override;
    bool default_neq(const Fitness &other) const;

};


#endif //RATATOSKR_FITNESSWRAPPER_H
