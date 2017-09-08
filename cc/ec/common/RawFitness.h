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
     * An ordinary fitness measure that is compared based on a reversed natural order.
     */
    float   _fitness;

public:
    explicit RawFitness(const Session &session);

    /**
    * Estimates if the evaluation of the individual results in a fitness of zero.
    */
    bool isIdeal() override;

    bool operator<(Fitness &other) override;
    bool operator<=(Fitness &other) override;
    bool operator>(Fitness &other) override;
    bool operator>=(Fitness &other) override;
    bool operator==(Fitness &other) override;

    float fitness() const;
    void  fitness(float fitness);

    RawFitness * clone() const override;

};


#endif //NDEC_RAWFITNESS_H
