#ifndef RATATOSKR_REPRESENTATION_H
#define RATATOSKR_REPRESENTATION_H


#include "representation/Genotype.h"
#include "representation/InitializationOperator.h"
#include "representation/VariationOperator.h"

/**
 * Represents a container class for all components of the genetic level. It defines the search space and how to
 * manipulate its points.
 *
 * @author  FelixVoelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class Representation {

public:
    Representation(Genotype &genotype, InitializationOperator &init, std::vector<VariationOperator *> &vary);

    Genotype& getGenotype();
    InitializationOperator& getInitializationOperator();
    std::vector<VariationOperator *>& getVariationOperators();

private:
    Genotype &genotype;
    InitializationOperator &init;
    std::vector<VariationOperator *> &vary;

};


#endif //RATATOSKR_REPRESENTATION_H
