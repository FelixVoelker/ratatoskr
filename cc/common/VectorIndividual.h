#ifndef RATATOSKR_VECTORINDIVIDUAL_H
#define RATATOSKR_VECTORINDIVIDUAL_H


#include <vector>
#include "../../core/representation/Individual.h"
#include "Configuration.h"
#include "FeatureVector.h"

/**
 * A vector individual as used by several types of Neuro-Dynamic Evolutionary Algorithms (NDEAs). This numerical vector
 * is called a chromosome whose elements are denoted as genes. These genes can be arbitrary numeric numbers, e.g.
 * binary values as in the case of a Neuro-Dynamic Genetic Algorithm (NDGA).
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class VectorIndividual : public Individual {

public:
    explicit VectorIndividual(const common::Configuration &configuration,
                              FeatureVector *featurevector,
                              Relevance *relevance);

    /**
     * Returns a human readable representation of the chromosome. This representation is a bit string for a binary
     * vector and a row vector for arbitrary numerical vectors.
     */
    std::string toString() override;

    VectorIndividual * clone() const override;

    std::vector<float> & getChromosome();

protected:
    std::vector<float> chromosome;

    VectorIndividual(const VectorIndividual &obj);

};


#endif //RATATOSKR_VECTORINDIVIDUAL_H
