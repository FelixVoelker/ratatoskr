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

    int epochs;

    Relevance(const Relevance &obj);

public:
    explicit Relevance(const Session &session);
    virtual ~Relevance();

    virtual float relevance(int epoch) = 0;

    Fitness & getFitness() const;

};


#endif //NDEC_RELEVANCE_H
