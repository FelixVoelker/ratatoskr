#ifndef NDEC_INDIVIDUAL_H
#define NDEC_INDIVIDUAL_H

#include "Fitness.h"
#include "FeatureMap.h"


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

    Fitness    **fitness;
    FeatureMap **featuremap;

    Individual(Individual &obj);

public:
    explicit Individual(Session &session);
    ~Individual();

    /**
     * Returns a human-readable representation of the individual.
     * @return The string representing the individual.
     */
    virtual string toString() = 0;

    Fitness    & getFitness();
    FeatureMap & getFeaturemap();

    bool evaluated();

    void evaluated(bool evaluated);

};


#endif //NDEC_INDIVIDUAL_H
