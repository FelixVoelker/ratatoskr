#ifndef RATATOSKR_FEATUREMAP_H
#define RATATOSKR_FEATUREMAP_H


#include "../util/Prototype.h"

/**
 * The abstract base class for an individual's feature map in a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e.
 * a mapping from the genotype of an individual to some numeric features. Each feature map takes part in the
 * preprocessing step that generates the input of the evolutionary network at each generation. Accordingly, each map
 * has to take the individual's representation into account in order to provide the evolutionary network with
 * highly informative data.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.12.2017
 */
class FeatureMap : public Prototype {

public:
    explicit FeatureMap(const core::Configuration &configuration);

    virtual FeatureMap * clone() const = 0;
};


#endif //RATATOSKR_FEATUREMAP_H
