#ifndef RATATOSKR_VARIATIONSOURCEWRAPPER_H
#define RATATOSKR_VARIATIONSOURCEWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/variation/VariationSource.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of VariationSource.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   30.12.2017
 */
class VariationSourceWrapper : public VariationSource, public wrapper<VariationSource> {

public:
    explicit VariationSourceWrapper(Configuration &configuration);

    unsigned long expectedSources() const override;

    std::vector<Individual *> perform(std::vector<Individual *> &parents, Thread &thread) const override;

};


#endif //RATATOSKR_VARIATIONSOURCEWRAPPER_H
