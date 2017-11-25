#include "TestFeatureMap.h"

TestFeatureMap::TestFeatureMap(Session &session) : FeatureMap(session) {}

TestFeatureMap * TestFeatureMap::clone() const {
    return new TestFeatureMap(*this);
}
