#ifndef NDEC_FEATUREMAPWRAPPER_H
#define NDEC_FEATUREMAPWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/FeatureMap.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class FeatureMapWrapper : public FeatureMap, public wrapper<FeatureMap> {

public:
    explicit FeatureMapWrapper(boost::shared_ptr<Session> session);

    FeatureMap * clone() override;
};


#endif //NDEC_FEATUREMAPWRAPPER_H
