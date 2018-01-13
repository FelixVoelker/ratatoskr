#ifndef RATATOSKR_EVOLUTIONARYSYSTEM_H
#define RATATOSKR_EVOLUTIONARYSYSTEM_H


#include "evaluation/Evaluator.h"
#include "experience/Replayer.h"
#include "initialization/Initializer.h"
#include "representation/Population.h"
#include "statistics/Statistics.h"
#include "variation/Breeder.h"

/**
 * The core system that runs a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e. it evolves its evolutionary system
 * either over a total number of generations or until an ideal individual has been acquired. Each evolution forms here
 * a simulation that is called an episode of the algorithm. In Neuro-Dynamic Evolutionary Computation (NDEC), a neural
 * network is trained in order to approximate some cost structure. This is done over a total number of consecutive
 * episodes that are organized into epochs. The core system does not only execute this workflow, it is also
 * self-contained in regard of the problem to be solved and the session to run.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   3.1.2018
 */
class EvolutionarySystem {

public:
    explicit EvolutionarySystem(const core::Configuration &configuration,
                                Builder *builder,
                                const std::function<void(Individual &, Thread &)> &eval,
                                EvolutionaryNetwork *network,
                                BreedingOperator *variation_tree);

    /**
     * Runs consecutive episodes of the evolutionary system until the total number of epochs has been processed.
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
     * Evolves the evolutionary system over a number of generations or until an ideal individual has been found.
     */
    void evolve();

};


#endif //RATATOSKR_EVOLUTIONARYSYSTEM_H
