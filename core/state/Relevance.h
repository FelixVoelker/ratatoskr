#ifndef RATATOSKR_RELEVANCE_H
#define RATATOSKR_RELEVANCE_H


#include "../util/Clonable.h"

/**
 * The standard class for an individual's relevance in a Actor-Critic Evolutionary Algorithm (ACEA), i.e. an alignment
 * strategy between the standarized fitness as described in "John R. Koza. Genetic Programming: On the Programming of
 * Computers by Means of Natural Selection (1992)" and the cost-to-go as described in "Dimitri P. Bertsekas,
 * John Tsitsiklis. Neuro-Dynamic Programming (1996)".
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   7.3.2019
 */
class Relevance : public Clonable {

public:
    Relevance();

    /**
     * Computes the relevance of an individual.
     */
    float compute() const;

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

    Relevance * clone() const override;

    float getCritic() const;
    float getFitness() const;
    void  setCritic(float critic);
    void  setFitness(float fitness);

protected:
    float fitness;
    float critic;

    Relevance(const Relevance &obj);
};


#endif //RATATOSKR_RELEVANCE_H
