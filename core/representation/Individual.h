#ifndef RATATOSKR_INDIVIDUAL_H
#define RATATOSKR_INDIVIDUAL_H


#include <string>
#include "FeatureMap.h"
#include "Relevance.h"

/**
 * The abstract base class of an individual within the population of an evolutionary system. It provides all
 * functionality of the individual as a solution of an optimization problem and maintains all problem-dependent
 * components to drive a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e. its relevance and feature map.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Individual : public Prototype {

public:
    explicit Individual(const core::Configuration &configuration, FeatureMap *featuremap, Relevance *relevance);
    ~Individual();

    /**
     * Returns a human-readable representation of the individual.
     */
    virtual std::string toString() = 0;

    Individual * clone() const = 0;

    FeatureMap & getFeaturemap() const;
    Relevance  & getRelevance() const;

    bool isEvaluated() const;
    void setEvaluated(bool evaluated);

protected:
    bool evaluated = false;

    FeatureMap *featuremap;
    Relevance  *relevance;

    Individual(const Individual &obj);

};


#endif //RATATOSKR_INDIVIDUAL_H
