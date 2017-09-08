#ifndef NDEC_FITNESS_H
#define NDEC_FITNESS_H


#include "../util/Prototype.h"

/**
 *  The interface for an individual's fitness that presents all functionality that a fitness measure has to be
 *  provided with in order to be used by a run of a particular Neuro-Dynamic Evolutionary Computation (NDEC) method.
 *
 *  @author  Felix Voelker
 *  @version 0.1
 *  @since   3.8.2017
 */
class Fitness : public Prototype {

public:
    explicit Fitness(const Session &session);

    /**
     * Estimates if the current fitness fulfills the termination criteria of the NDEC method.
     * @return True if individual has ideal fitness, false otherwise.
     */
    virtual bool isIdeal() = 0;

    virtual bool operator<(Fitness &other) = 0;
    virtual bool operator<=(Fitness &other) = 0;
    virtual bool operator>(Fitness &other)  = 0;
    virtual bool operator>=(Fitness &other) = 0;
    virtual bool operator==(Fitness &other) = 0;

};


#endif //NDEC_FITNESS_H