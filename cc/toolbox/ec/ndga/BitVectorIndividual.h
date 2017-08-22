#ifndef NDEC_BITVECTORINDIVIDUAL_H
#define NDEC_BITVECTORINDIVIDUAL_H

#include <vector>

#include "../../../../core/representation/Individual.h"

using namespace std;


/**
 * An individual of conventional Genetic Algorithms, i.e. its representation is a vector of binary values.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.7.2017
 */
class BitVectorIndividual : public Individual {

private:
    vector<unsigned int> chromosome;

public:
    explicit BitVectorIndividual(Session &session);
    BitVectorIndividual(BitVectorIndividual &obj);

    /**
     * Returns the bit string representation of the chromosome.
     */
    string toString() override;

    vector<unsigned int> & getChromosome();

    BitVectorIndividual * clone() override;

};


#endif //NDEC_NDGAINDIVIDUAL_H
