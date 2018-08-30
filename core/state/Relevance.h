#ifndef RATATOSKR_RELEVANCE_H
#define RATATOSKR_RELEVANCE_H


#include "../util/Clonable.h"

/**
 * @todo change comment
 * The standard class for the conventional measure of an individual's relevance in a Neuro-Dynamic Evolutionary
 * Algorithm (NDEA), i.e. an alignment strategy between the standarized fitness as described in "John R. Koza. Genetic
 * Programming: On the Programming of Computers by Means of Natural Selection (1992)" and the cost-to-go as described
 * in "Dimitri P. Bertsekas, John Tsitsiklis. Neuro-Dynamic Programming (1996)".
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Relevance : public Clonable {

public:
    Relevance();

    /**
     * Estimates if the current fitness fulfills the termination criteria of a conventional NDEA, i.e.
     * the individual has a fitness of zero.
     * @return True if individual has ideal fitness, false otherwise.
     */
    virtual bool isIdeal() const;

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

    float getCriticism() const;
    float getFitness() const;
    void  setCriticism(float criticism);
    void  setFitness(float fitness);

protected:
    float fitness;
    float criticism;

    Relevance(const Relevance &obj);
};


#endif //RATATOSKR_RELEVANCE_H
