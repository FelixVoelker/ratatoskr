#ifndef RATATOSKR_FEATUREVECTOR_H
#define RATATOSKR_FEATUREVECTOR_H


#include <vector>

#include "../../../core/representation/FeatureMap.h"
#include "NDGASession.h"

/**
 * A simple feature map that performs an identity function from a numerical vector to a vector of floats.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   7.1.2018
 */
class FeatureVector : public FeatureMap {

public:
    explicit FeatureVector(NDGASession &session);

    /**
     * Returns the bit vector as a vector of floats.
     * @returns {0,1}^n
     */
    std::vector<float> & compute(std::vector<float> &chromosome) const;

    FeatureVector * clone() const override;
    
};


#endif //RATATOSKR_FEATUREVECTOR_H
