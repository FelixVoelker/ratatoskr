#ifndef NDEC_EVOLUTIONARYSYSTEM_H
#define NDEC_EVOLUTIONARYSYSTEM_H

#include "representation/Population.h"
#include "evaluation/Evaluator.h"
#include "util/Randomizer.h"
#include "variation/Breeder.h"
#include "statistics/Statistics.h"


/**
 * Represents the entire evolutionary system that controls the evolutionary run.
 *
 * @author Felix Voelker
 * @version 0.1
 * @since   8.8.2017
 */
class EvolutionarySystem {

private:


    Population population;

    Evaluator evaluator;
    Breeder   breeder;

    Statistics statistics;

    bool train = false;
    int EPOCHS              = 100;
    int TRAINING_EPISODES   = 100000;
    int TESTING_EPISODES    = 1000;
    unsigned int GENERATIONS;

public:
    explicit EvolutionarySystem(Session &session);
    ~EvolutionarySystem();

    void run();

};


#endif //NDEC_EVOLUTIONARYSYSTEM_H
