#ifndef RATATOSKR_VECTOR_H
#define RATATOSKR_VECTOR_H


#include <string>
#include <vector>
#include "../../core/representation/Genotype.h"

/**
 * @todo change comment
 * A vector individual as used by several types of Neuro-Dynamic Evolutionary Algorithms (NDEAs). This numerical vector
 * is called a chromosome whose elements are denoted as genes. These genes can be arbitrary numeric numbers, e.g.
 * binary values as in the case of a Neuro-Dynamic Genetic Algorithm (NDGA).
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   12.10.2018
 */
class Vector {

public:
    class Chromosome : Genotype {

    public:
        explicit Chromosome(unsigned int genes);

        /**
         * Returns the chromosome as a row numerical vector.
         */
        std::string toString() override;

        std::vector<float> & getChromosome();

        Genotype * clone() const override;

    protected:
        std::vector<float> chromosome;

        Chromosome(const Chromosome &obj);
    };

};


#endif //RATATOSKR_VECTOR_H
