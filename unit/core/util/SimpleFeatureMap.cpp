#include "SimpleFeatureMap.h"

SimpleFeatureMap::SimpleFeatureMap(Session &session) : FeatureMap(session) {}

SimpleFeatureMap * SimpleFeatureMap::clone() const {
    return new SimpleFeatureMap(*this);
}
