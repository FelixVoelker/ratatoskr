#ifndef RATATOSKR_CORE_TESTFEATUREMAP_H
#define RATATOSKR_CORE_TESTFEATUREMAP_H


#include "../../../core/representation/FeatureMap.h"

/**
 * An instance of FeatureMap to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestFeatureMap : public FeatureMap {

public:
    explicit TestFeatureMap(Session &session);

    TestFeatureMap * clone() const override;

};


#endif //RATATOSKR_CORE_TESTFEATUREMAP_H
