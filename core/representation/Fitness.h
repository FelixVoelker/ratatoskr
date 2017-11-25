#ifndef NDEC_FITNESS_H
#define NDEC_FITNESS_H


#include "../util/Prototype.h"

/**
 *  The blueprint class for an individual's fitness in Ratatoskr. It represents the conventional fitness measure of all
 *  Neuro-Dynamic Evolutionary Computation (NDEC) methods, i.e. a standarized fitness as described in "John R. Koza. Genetic
 *  Programming: On the Programming of Computers by Means of Natural Selection (1992)".
 *
 *  @author  Felix Voelker
 *  @version 0.2
 *  @since   10.9.2017
 */
class Fitness : public Prototype {

protected:
    /**
     * The standarized fitness measure that is compared based on a reversed natural order.
     */
    float   _fitness;

public:
    explicit Fitness(const Session &session);

    /**
     * Estimates if the current fitness fulfills the termination criteria of a conventional NDEC method, i.e.
     * an individual has a fitness of zero.
     * @return True if individual has ideal fitness, false otherwise.
     */
    virtual bool isIdeal() const;

    virtual bool operator<(const Fitness &other) const;
    virtual bool operator<=(const Fitness &other) const;
    virtual bool operator>(const Fitness &other) const;
    virtual bool operator>=(const Fitness &other) const;
    virtual bool operator==(const Fitness &other) const;

    float fitness() const;
    void  fitness(float fitness);

    Fitness * clone() const override;

};


#endif //NDEC_FITNESS_H