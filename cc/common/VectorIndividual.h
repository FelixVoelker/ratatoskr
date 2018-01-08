#ifndef RATATOSKR_VECTORINDIVIDUAL_H
#define RATATOSKR_VECTORINDIVIDUAL_H


#include <vector>
#include "../../core/representation/Individual.h"
#include "Configuration.h"


/**
 * TODO: Comments
 * An individual of conventional Genetic Algorithms, i.e. its representation is a vector of binary values.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.7.2017
 */
class VectorIndividual : public Individual {

public:
    explicit VectorIndividual(common::Configuration &configuration,
                              Cost *cost,
                              FeatureMap *featuremap,
                              Fitness *fitness);

    /**
     * Returns the bit string representation of the chromosome.
     */
    std::string toString() override;

    VectorIndividual * clone() const override;

    std::vector<float> & getChromosome();

protected:
    std::vector<float> chromosome;

    VectorIndividual(const VectorIndividual &obj);

};


#endif //RATATOSKR_VECTORINDIVIDUAL_H
