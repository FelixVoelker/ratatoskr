#ifndef NDEC_RAWFITNESS_H
#define NDEC_RAWFITNESS_H


#include "../../../../core/representation/Fitness.h"

/**
 * Represents the simplest fitness measure in evolutionary algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   31.7.2017
 */
class RawFitness : public Fitness {

protected:
    /**
     * An ordinary fitness measure that is compared based on a natural order and
     * the number of unsuccessful fitness cases that are defined by a problem.
     */
    float   fitness;
    float   real_fitness;
    int     hits = -1;

public:
    explicit RawFitness(Session &session);

    /**
    * Estimates if the evaluation of the individual results in no unsuccessful fitness cases.
    * @return True if hits is zero, false otherwise.
    */
    bool isIdeal() override;

    bool operator<(Fitness &other) override;
    bool operator<=(Fitness &other) override;
    bool operator>(Fitness &other) override;
    bool operator>=(Fitness &other) override;
    bool operator==(Fitness &other) override;

    float getFitness();
    int   getHits();
    void  setFitness(float fitness);
    void  setHits(int hits);

    RawFitness * clone() override;

};


#endif //NDEC_RAWFITNESS_H
