#ifndef NDEC_FEATUREVECTOR_H
#define NDEC_FEATUREVECTOR_H


#include <vector>

#include "../../../core/representation/FeatureMap.h"
#include "NDGASession.h"

using namespace std;

/**
 * A simple feature map that performs an identity function from a numerical vector to a vector of floats.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.7.2017
 */
class FeatureVector : public FeatureMap {

public:
    explicit FeatureVector(NDGASession &session);

    /**
     * Returns the bit vector as a vector of floats.
     * @returns {0,1}^n
     */
    vector<float> compute(vector<unsigned int> &chromosome);

    FeatureVector * clone() override;
    
};


#endif //NDEC_FEATUREVECTOR_H
