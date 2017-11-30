#ifndef RATATOSKR_COST_H
#define RATATOSKR_COST_H


#include "Fitness.h"

/**
 * The blueprint class for an individual's relevance in Ratatoskr. It represents the conventional relevance measure of
 * all Neuro-Dynamic Evolutionary Computation (NDEC) methods.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   16.11.2017
 */
class Cost : public Prototype {

protected:
    /**
     * The standard cost measure that approximates the optimal cost-to-go of a stochastic shortest path problem.
     */
    float approximateCost;

    Cost(const Cost &obj);

public:
    explicit Cost(const Session &session);

    /**
     * Computes the
     */
    float targetCost() const;

    Cost* clone() const override;

    float getApproximateCost() const;
    void  setApproximateCost(float cost);

};


#endif // RATATOSKR_COST_H
