#ifndef RATATOSKR_INDIVIDUAL_H
#define RATATOSKR_INDIVIDUAL_H


#include "Relevance.h"
#include "../representation/Genotype.h"

/**
 * %todo: change comments
 * The abstract base class of an individual within the population of an evolutionary system. It provides all
 * functionality of the individual as a solution of an optimization problem and maintains all problem-dependent
 * components to drive a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e. its relevance and feature map.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   15.7.2018
 */
class Individual {

public:
    explicit Individual(Genotype &genotype, Relevance &relevance);
    Individual(const Individual &obj);
    ~Individual();

    Genotype & getGenotype() const;
    Relevance  & getRelevance() const;

protected:
    Genotype *genotype;
    Relevance *relevance;

};


#endif //RATATOSKR_INDIVIDUAL_H
