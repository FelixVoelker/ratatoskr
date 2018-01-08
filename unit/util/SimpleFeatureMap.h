#ifndef RATATOSKR_UNIT_SIMPLEFEATUREMAP_H
#define RATATOSKR_UNIT_SIMPLEFEATUREMAP_H


#include "../../core/representation/FeatureMap.h"

/**
 * A simple instance of FeatureMap to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   12.12.2017
 */
class SimpleFeatureMap : public FeatureMap {

public:
    explicit SimpleFeatureMap(Configuration &configuration);

    SimpleFeatureMap * clone() const override;

};


#endif //RATATOSKR_UNIT_SIMPLEFEATUREMAP_H
