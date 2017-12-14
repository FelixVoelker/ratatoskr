#ifndef RATATOSKR_INDIVIDUAL_H
#define RATATOSKR_INDIVIDUAL_H


#include <string>
#include "Cost.h"
#include "FeatureMap.h"
#include "Fitness.h"

/**
 * The abstract base class of an individual within the population of an evolutionary system. It provides all
 * functionality of the individual as a solution of an optimization problem and maintains all problem-dependent
 * components to drive a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e. its cost, fitness and feature map.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   14.12.2017
 */
class Individual : public Prototype {

public:
    explicit Individual(const Session &session);
    ~Individual();

    /**
     * Computes the relevance of an individual according to the given fraction, i.e. the alignment factor
     * between its fitness and cost.
     * @param fraction Decimal number within the interval [0,1] with 0 being fitness only and 1 being cost only.
     * Out of scope numbers are projected on the boundary of the interval.
     */
    float relevance(float fraction);

    /**
     * Returns a human-readable representation of the individual.
     */
    virtual std::string toString() = 0;

    Individual * clone() const = 0;

    Cost       & getCost() const;
    FeatureMap & getFeaturemap() const;
    Fitness    & getFitness() const;

    bool isEvaluated() const;
    void setEvaluated(bool evaluated);

protected:
    bool evaluated = false;

    /** Components */
    Cost        *cost;
    FeatureMap  *featuremap;
    Fitness     *fitness;

    Individual(const Individual &obj);

};


#endif //RATATOSKR_INDIVIDUAL_H
