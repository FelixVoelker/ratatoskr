#ifndef RATATOSKR_EVOLUTIONARYSYSTEM_H
#define RATATOSKR_EVOLUTIONARYSYSTEM_H


#include "representation/Population.h"
#include "evaluation/Evaluator.h"
#include "variation/Breeder.h"
#include "statistics/Statistics.h"
#include "experience/Replayer.h"
#include "initialization/Initializer.h"

/**
 * Represents the entire evolutionary system that controls the evolutionary run.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   3.1.2018
 */
class EvolutionarySystem {

public:
    explicit EvolutionarySystem(Session &session);

    /**
     *
     */
    void run();

    Statistics & getStatistics();

private:
    bool complete;
    unsigned int epochs;
    unsigned int episodes;
    unsigned int generations;

    unsigned int epoch;

    /** Components */
    Population  population;
    Initializer initializer;
    Evaluator   evaluator;
    Breeder     breeder;
    Replayer    replayer;
    Statistics  statistics;

    /**
     *
     */
    void evolve();

};


#endif //RATATOSKR_EVOLUTIONARYSYSTEM_H
