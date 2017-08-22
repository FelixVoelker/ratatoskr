#ifndef NDEC_KOZAFITNESS_H
#define NDEC_KOZAFITNESS_H

#include "../../../../core/representation/Fitness.h"


/**
 *  Represents the fitness of koza-based Genetic Programming as described in "John R. Koza. Genetic Programming:
 *  On the Programming of Computers by Means of Natural Selection (1992)".
 *  @author Felix Voelker
 *  @version 0.1
 *  @since 5.5.2017
 */
class KozaFitness : public Fitness {

private:
    float standarized_fitness = 0;

public:
    float adjustedFitness();
    bool  isIdeal();

    float standarizedFitness();
    void  setStandarizedFitness(float standarized_fitness);

    bool operator<(Fitness& other);
    bool operator<=(Fitness& other);
    bool operator>(Fitness& other);
    bool operator>=(Fitness& other);
    bool operator==(Fitness& other);

    virtual KozaFitness* clone();
};


#endif //NDEC_KOZAFITNESS_H
