#ifndef NDEC_RAWFITNESS_H
#define NDEC_RAWFITNESS_H


#include "../../../core/representation/Fitness.h"

/**
 * Represents the simplest fitness measure in neuro-dynamic evolutionary algorithms.
 *
 * @author  Felix Voelker
 * @version 0.2
 * @since   3.9.2017
 */
class RawFitness : public Fitness {

protected:
    /**
     * An ordinary fitness measure that is compared based on a natural order.
     */
    float   _fitness;
    float   _standarized_fitness;

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

    float fitness();
    float standarizedFitness();
    void  fitness(float fitness);
    void  standarizedFitness(float standarizedFitness);

    RawFitness * clone() override;

};


#endif //NDEC_RAWFITNESS_H
