#ifndef RATATOSKR_COSTWRAPPER_H
#define RATATOSKR_COSTWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Cost.h"

using namespace boost::python;


/**
 * Boost.Python wrapper to expose all virtual core functionality of Cost.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   1.12.2017
 */
class CostWrapper : public Cost, public wrapper<Cost> {

public:
    explicit CostWrapper(Configuration &configuration);

    bool operator<(const Cost &other) const override;
    bool default_lt(const Cost &other) const;
    bool operator<=(const Cost &other) const override;
    bool default_leq(const Cost &other) const;
    bool operator>(const Cost &other) const override;
    bool default_gt(const Cost &other) const;
    bool operator>=(const Cost &other) const override;
    bool default_geq(const Cost &other) const;
    bool operator==(const Cost &other) const override;
    bool default_eq(const Cost &other) const;
    bool operator!=(const Cost &other) const override;
    bool default_neq(const Cost &other) const;

};


#endif //RATATOSKR_COSTWRAPPER_H
