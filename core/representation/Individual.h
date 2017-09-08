#ifndef NDEC_INDIVIDUAL_H
#define NDEC_INDIVIDUAL_H


#include "FeatureMap.h"
#include "Relevance.h"

/**
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
    bool _evaluated = false;

    Relevance  *relevance;
    FeatureMap *featuremap;

    Individual(const Individual &obj);

public:
    explicit Individual(const Session &session);
    virtual ~Individual();

    /**
     * Returns a human-readable representation of the individual.
     * @return The string representing the individual.
     */
    virtual string toString() = 0;

    Relevance  & getRelevance() const;
    FeatureMap & getFeaturemap() const;

    bool evaluated() const;
    void evaluated(bool evaluated);

};


#endif //NDEC_INDIVIDUAL_H
