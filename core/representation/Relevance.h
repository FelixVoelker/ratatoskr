#ifndef NDEC_RELEVANCE_H
#define NDEC_RELEVANCE_H


#include "Fitness.h"

/**
 * The blueprint class for an individual's relevance in Ratatoskr. It represents the conventional relevance measure of
 * all Neuro-Dynamic Evolutionary Computation (NDEC) methods.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   10.9.2017
 */
class Relevance : public Prototype {

protected:
    int EPOCHS;

    Fitness *fitness;

    /**
     * The standard cost measure that approximates the optimal cost-to-go.
     */
    float _cost;

    Relevance(const Relevance &obj);

public:
    explicit Relevance(const Session &session);
    ~Relevance() override;

    /**
     * Computes the current relevance of the individual with an alignment strategy.
     * @param epoch Current epoch of the evolutionary run.
     */
    virtual float relevance(int epoch);

    Fitness & getFitness() const;

    float cost() const;
    void cost(float cost);

    Relevance* clone() const override;

};


#endif //NDEC_RELEVANCE_H
