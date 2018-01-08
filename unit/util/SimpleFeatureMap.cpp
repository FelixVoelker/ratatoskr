#include "SimpleFeatureMap.h"

SimpleFeatureMap::SimpleFeatureMap(Configuration &configuration) : FeatureMap(configuration) {}

SimpleFeatureMap * SimpleFeatureMap::clone() const {
    return new SimpleFeatureMap(*this);
}
