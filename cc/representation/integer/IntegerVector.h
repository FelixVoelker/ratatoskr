#ifndef RATATOSKR_INTEGERVECTOR_H
#define RATATOSKR_INTEGERVECTOR_H


#include <vector>
#include "../../../core/representation/Genotype.h"

/**
 * Represents a genotype that encodes solutions as n-dimensional integer vectors. In the terminology of evolutionary
 * algorithms, each vector is called a chromosome and each placeholder a gene. Accordingly, its dimensionality is given
 * by the number of genes.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   8.11.2018
 */
class IntegerVector : public Genotype {

public:
    explicit IntegerVector(unsigned int genes);

    /**
     * Returns the chromosome as n-dimensional integer vector.
     */
    std::string toString() override;

    std::vector<int>& getChromosome();

    IntegerVector* clone() const override;

protected:
    std::vector<int> chromosome;

    IntegerVector(const IntegerVector &obj);
};


#endif //RATATOSKR_INTEGERVECTOR_H
