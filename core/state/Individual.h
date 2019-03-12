#ifndef RATATOSKR_INDIVIDUAL_H
#define RATATOSKR_INDIVIDUAL_H


#include "Relevance.h"
#include "../representation/Genotype.h"
#include "../Representation.h"

/**
 * The abstract base class of an individual within the population of an evolutionary system. It contains all components
 * of an individual's state and provides the functionality for maintainance and comparison on the individual level.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   7.3.2019
 */
class Individual {

public:
    explicit Individual(Representation &representation);
    Individual(const Individual &obj);
    ~Individual();

    Genotype& getGenotype() const;
    Relevance& getRelevance() const;

protected:
    Genotype *genotype;
    Relevance *relevance;

};

#endif //RATATOSKR_INDIVIDUAL_H
