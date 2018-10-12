#include "SimpleFeatureMap.h"

SimpleFeatureMap::SimpleFeatureMap(const core::Configuration &configuration) : FeatureMap(configuration) {}

SimpleFeatureMap * SimpleFeatureMap::clone() const {
    return new SimpleFeatureMap(*this);
}
