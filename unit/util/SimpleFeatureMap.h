#ifndef RATATOSKR_UNIT_SIMPLEFEATUREMAP_H
#define RATATOSKR_UNIT_SIMPLEFEATUREMAP_H


#include "../../core/representation/FeatureMap.h"

/**
 * A simple instance of FeatureMap to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class SimpleFeatureMap : public FeatureMap {

public:
    explicit SimpleFeatureMap(const core::Configuration &configuration);

    SimpleFeatureMap * clone() const override;

};


#endif //RATATOSKR_UNIT_SIMPLEFEATUREMAP_H
