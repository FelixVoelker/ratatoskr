#ifndef RATATOSKR_BINARYVECTOR_H
#define RATATOSKR_BINARYVECTOR_H


#include <vector>
#include "../../../core/representation/Genotype.h"

/**
 * A vector individual as used by several types of Neuro-Dynamic Evolutionary Algorithms (NDEAs). This numerical vector
 * is called a chromosome whose elements are denoted as genes. These genes can be arbitrary numeric numbers, e.g.
 * binary values as in the case of a Neuro-Dynamic Genetic Algorithm (NDGA).
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   13.10.2018
 */
class BitString : public Genotype {

public:
    explicit BitString(unsigned int genes);

    /**
     * Returns the chromosome as a bit string.
     */
    std::string toString() override;

    std::vector<bool> & getChromosome();

    BitString * clone() const override;

protected:
    std::vector<bool> chromosome;

    BitString(const BitString &obj);
};


#endif //RATATOSKR_BINARYVECTOR_H
