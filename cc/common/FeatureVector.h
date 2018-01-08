#ifndef RATATOSKR_FEATUREVECTOR_H
#define RATATOSKR_FEATUREVECTOR_H


#include <vector>
#include "../../core/representation/FeatureMap.h"
#include "Configuration.h"

/**
 * A simple feature map that performs an identity function on a numerical vector, e.g. a chromosome.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   8.1.2018
 */
class FeatureVector : public FeatureMap {

public:
    explicit FeatureVector(common::Configuration &configuration);

    /**
     * Performs the identity function on a chromosome, i.e. some numerical vector.
     */
    std::vector<float> & compute(std::vector<float> &chromosome) const;

    FeatureVector * clone() const override;
    
};


#endif //RATATOSKR_FEATUREVECTOR_H
