#ifndef RATATOSKR_BUILDERWRAPPER_H
#define RATATOSKR_BUILDERWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/initialization/Builder.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Builder.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   27.12.2017
 */
class BuilderWrapper : public Builder, public wrapper<Builder> {

public:
    explicit BuilderWrapper(Configuration &configuration, Individual *prototype);

    void initialize(Individual &individual, Thread &thread) const override;
};


#endif //RATATOSKR_BUILDERWRAPPER_H
