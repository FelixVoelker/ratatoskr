#ifndef NDEC_EVOLUTIONARYSYSTEM_H
#define NDEC_EVOLUTIONARYSYSTEM_H

#include "representation/Population.h"
#include "evaluation/Evaluator.h"
#include "util/Randomizer.h"
#include "variation/Breeder.h"
#include "statistics/Statistics.h"
#include "experience/Replayer.h"


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
    Replayer  replayer;

    Statistics statistics;

    unsigned int EPOCHS;
    unsigned int EPISODES;
    unsigned int GENERATIONS;

    void evolve(unsigned int epoch);

public:
    explicit EvolutionarySystem(Session &session);
    ~EvolutionarySystem();

    void run();

    Statistics getStatistics();

};


#endif //NDEC_EVOLUTIONARYSYSTEM_H
