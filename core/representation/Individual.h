#ifndef RATATOSKR_INDIVIDUAL_H
#define RATATOSKR_INDIVIDUAL_H


#include <string>
#include "FeatureMap.h"
#include "Cost.h"

/**
 * TODO: Comments
 * The blueprint class of individuals within a population that provides all functionality in regard of the
 * individual as an entity of the evolutionary system. Accordingly, it maintains its Fitness and
 * FeatureMap objects.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class Individual : public Prototype {

protected:
    bool evaluated = false;

    /** Components */
    Cost        *cost;
    FeatureMap  *featuremap;
    Fitness     *fitness;

    Individual(const Individual &obj);

public:
    explicit Individual(const Session &session);
    virtual ~Individual();

    /**
     * Computes the relevance of an individual according to the given fraction, i.e. the approaching factor
     * between its fitness or cost. Alignment strategy
     * @param fraction Decimal number of the interval [0,1] with 0 being fitness only and 1 being cost only.
     */
    float relevance(float fraction);

    /**
     * Returns a human-readable representation of the individual.
     * @return The string representing the individual.
     */
    virtual std::string toString() = 0;

    Cost       & getCost() const;
    FeatureMap & getFeaturemap() const;
    Fitness    & getFitness() const;

    bool isEvaluated() const;
    void setEvaluated(bool evaluated);

};


#endif // RATATOSKR_INDIVIDUAL_H
