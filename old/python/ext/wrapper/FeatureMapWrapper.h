#ifndef RATATOSKR_FEATUREMAPWRAPPER_H
#define RATATOSKR_FEATUREMAPWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/representation/FeatureMap.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of FeatureMap.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class FeatureMapWrapper : public FeatureMap, public wrapper<FeatureMap> {

public:
    explicit FeatureMapWrapper(const core::Configuration &configuration);

    FeatureMap * clone() const override;
};


#endif //RATATOSKR_FEATUREMAPWRAPPER_H
