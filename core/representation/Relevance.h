#ifndef RATATOSKR_RELEVANCE_H
#define RATATOSKR_RELEVANCE_H


#include "../util/Prototype.h"

/**
 * The standard class for the conventional measure of an individual's relevance in a Neuro-Dynamic Evolutionary
 * Algorithm (NDEA), i.e. an alignment strategy between the standarized fitness as described in "John R. Koza. Genetic
 * Programming: On the Programming of Computers by Means of Natural Selection (1992)" and the cost-to-go as described
 * in "Dimitri P. Bertsekas, John Tsitsiklis. Neuro-Dynamic Programming (1996)".
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class Relevance : public Prototype {

public:
    explicit Relevance(const core::Configuration &configuration);

    /**
     * Computes the cost error value for the TD-Learning update rule.
     * @param discount_factor Numeric value of [0,1] that scales the effect of long-term costs.
     * @param fitness         Current standarized fitness of the corresponding individual at position k.
     * @param next            Approximate cost-to-go of the offspring at position k.
     */
    float error(float discount_factor, float fitness, float next) const;

    /**
     * Estimates if the current fitness fulfills the termination criteria of a conventional NDEA, i.e.
     * the individual has a fitness of zero.
     * @return True if individual has ideal fitness, false otherwise.
     */
    virtual bool isIdeal() const;

    /**
     * Computes the relevance of an individual according to the given fraction, i.e. the alignment factor
     * between its fitness and cost with 0 being fitness only and 1 being cost only.
     */
    float relevance() const;

    /**
     * Computes the adjusted relevance of an individual.
     */
    float adjustedRelevance() const;

    virtual bool operator<(const Relevance &other) const;
    virtual bool operator<=(const Relevance &other) const;
    virtual bool operator>(const Relevance &other) const;
    virtual bool operator>=(const Relevance &other) const;
    virtual bool operator==(const Relevance &other) const;
    virtual bool operator!=(const Relevance &other) const;

    virtual Relevance * clone() const;

    float getCost() const;
    float getFitness() const;
    float getFraction() const;
    void  setCost(float cost);
    void  setFitness(float fitness);
    void  setFraction(float fraction);

protected:
    float cost;
    float fitness;
    float fraction;

    Relevance(const Relevance &obj);
};


#endif //RATATOSKR_RELEVANCE_H
