#ifndef RATATOSKR_RELEVANCEWRAPPER_H
#define RATATOSKR_RELEVANCEWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/state/Relevance.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Relevance.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class RelevanceWrapper : public Relevance, public wrapper<Relevance> {

public:
    explicit RelevanceWrapper(const core::Configuration &configuration);

    bool isIdeal() const override;
    bool default_isIdeal() const;

    bool operator<(const Relevance &other) const override;
    bool default_lt(const Relevance &other) const;
    bool operator<=(const Relevance &other) const override;
    bool default_leq(const Relevance &other) const;
    bool operator>(const Relevance &other) const override;
    bool default_gt(const Relevance &other) const;
    bool operator>=(const Relevance &other) const override;
    bool default_geq(const Relevance &other) const;
    bool operator==(const Relevance &other) const override;
    bool default_eq(const Relevance &other) const;
    bool operator!=(const Relevance &other) const override;
    bool default_neq(const Relevance &other) const;

};


#endif //RATATOSKR_RELEVANCEWRAPPER_H
