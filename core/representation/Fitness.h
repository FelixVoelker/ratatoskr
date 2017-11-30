#ifndef RATATOSKR_FITNESS_H
#define RATATOSKR_FITNESS_H


#include "../util/Prototype.h"

/**
 *  The standard class for the conventional measure of an individual's fitness in a Neuro-Dynamic
 *  Evolutionary Algorithm (NDEA), i.e. the standarized fitness as described in "John R. Koza. Genetic
 *  Programming: On the Programming of Computers by Means of Natural Selection (1992)".
 *
 *  @author  Felix Voelker
 *  @version 0.0.2
 *  @since   30.11.2017
 */
class Fitness : public Prototype {

public:
    explicit Fitness(const Session &session);

    /**
     * Estimates if the current fitness fulfills the termination criteria of a conventional NDEA, i.e.
     * the individual has a fitness of zero.
     * @return True if individual has ideal fitness, false otherwise.
     */
    virtual bool isIdeal() const;

    virtual bool operator<(const Fitness &other) const;
    virtual bool operator<=(const Fitness &other) const;
    virtual bool operator>(const Fitness &other) const;
    virtual bool operator>=(const Fitness &other) const;
    virtual bool operator==(const Fitness &other) const;
    virtual bool operator!=(const Fitness &other) const;

    virtual Fitness * clone() const;

    float getFitness() const;
    void  setFitness(float fitness);

protected:
    /**
     * The standarized fitness that is compared based on a reversed natural order.
     */
    float fitness;

    Fitness(const Fitness &obj);

};


#endif //RATATOSKR_FITNESS_H