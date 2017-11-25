#ifndef NDEC_BITVECTORINDIVIDUAL_H
#define NDEC_BITVECTORINDIVIDUAL_H

#include <vector>

#include "../../../core/representation/Individual.h"
#include "NDGASession.h"

using namespace std;


/**
 * TODO: Comments
 * An individual of conventional Genetic Algorithms, i.e. its representation is a vector of binary values.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.7.2017
 */
class BitVectorIndividual : public Individual {

protected:
    vector<unsigned int> chromosome;

    BitVectorIndividual(const BitVectorIndividual &obj);

public:
    explicit BitVectorIndividual(const NDGASession &session);

    /**
     * Returns the bit string representation of the chromosome.
     */
    string toString() override;

    vector<unsigned int> & getChromosome();

    BitVectorIndividual * clone() const override;

};


#endif //NDEC_NDGAINDIVIDUAL_H
