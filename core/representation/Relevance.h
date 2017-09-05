#ifndef NDEC_RELEVANCE_H
#define NDEC_RELEVANCE_H


#include "Fitness.h"

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   1.9.2017
 */
class Relevance : public Prototype {

protected:
    Fitness *fitness;

    int EPOCHS;

    Relevance(Relevance &obj);

public:
    explicit Relevance(Session &session);
    ~Relevance();

    virtual float relevance(int epoch) = 0;

    Fitness & getFitness();

};


#endif //NDEC_RELEVANCE_H
