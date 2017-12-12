#ifndef RATATOSKR_FEATUREMAPWRAPPER_H
#define RATATOSKR_FEATUREMAPWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/FeatureMap.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of FeatureMap.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   12.12.2017
 */
class FeatureMapWrapper : public FeatureMap, public wrapper<FeatureMap> {

public:
    explicit FeatureMapWrapper(boost::shared_ptr<Session> session);

    FeatureMap * clone() const override;
};


#endif //RATATOSKR_FEATUREMAPWRAPPER_H
