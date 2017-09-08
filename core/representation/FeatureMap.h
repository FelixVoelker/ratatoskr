#ifndef NDEC_FEATUREMAP_H
#define NDEC_FEATUREMAP_H


#include "../util/Prototype.h"

/**
 * The interface for all FeatureMap objects of the NDEC framework. Each derived class is dependent on the
 * representation of the associated individual, i.e. its functionality has to provide feasible features in order to
 * generate the input for the evolutionary network.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class FeatureMap : public Prototype {

public:
    explicit FeatureMap(const Session &session);

};


#endif //NDEC_FEATUREMAP_H
