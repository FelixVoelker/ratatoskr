#ifndef RATATOSKR_BUILDERWRAPPER_H
#define RATATOSKR_BUILDERWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/initialization/Builder.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Builder.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class BuilderWrapper : public Builder, public wrapper<Builder> {

public:
    explicit BuilderWrapper(const core::Configuration &configuration, Individual *prototype);

    void initialize(Individual &individual, Thread &thread) const override;
};


#endif //RATATOSKR_BUILDERWRAPPER_H
