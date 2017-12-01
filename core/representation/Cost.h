#ifndef RATATOSKR_COST_H
#define RATATOSKR_COST_H


#include "Fitness.h"

/**
 * The standard class for the conventional measure of an individual's cost in a Neuro-Dynamic
 * Evolutionary Algorithm (NDEA), i.e. the cost-to-go as described in "Dimitri P. Bertsekas,
 * John Tsitsiklis. Neuro-Dynamic Programming (1996)".
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   1.12.2017
 */
class Cost : public Prototype {

public:
    explicit Cost(const Session &session);

    /**
     * Computes the error value for the TD-Learning update rule.
     * @param discount_factor Numeric value of [0,1] that scales the effect of long-term costs.
     * @param fitness         Current standarized fitness of the corresponding individual at position k.
     * @param next            Approximate cost-to-go of the offspring at position k.
     */
    float error(float discount_factor, float fitness, float next) const;

    virtual bool operator<(const Cost &other) const;
    virtual bool operator<=(const Cost &other) const;
    virtual bool operator>(const Cost &other) const;
    virtual bool operator>=(const Cost &other) const;
    virtual bool operator==(const Cost &other) const;
    virtual bool operator!=(const Cost &other) const;

    virtual Cost* clone() const;

    float getCost() const;
    void  setCost(float cost);

protected:
    /**
     * The current cost approximation of the given discounted optimization problem's cost-to-go.
     */
    float cost;

    Cost(const Cost &obj);

};


#endif //RATATOSKR_COST_H
