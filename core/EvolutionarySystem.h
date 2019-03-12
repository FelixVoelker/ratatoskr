#ifndef RATATOSKR_EVOLUTIONARYSYSTEM_H
#define RATATOSKR_EVOLUTIONARYSYSTEM_H


#include "Representation.h"
#include "state/Population.h"
#include "util/Thread.h"

/**
 * TODO: Change comments
 * The core system that runs a Neuro-Dynamic Evolutionary Algorithm (NDEA), i.e. it evolves its evolutionary system
 * either over a total number of generations or until an ideal individual has been acquired. Each evolution forms here
 * a simulation that is called an episode of the algorithm. In Neuro-Dynamic Evolutionary Computation (NDEC), a neural
 * network is trained in order to approximate some cost structure. This is done over a total number of consecutive
 * episodes that are organized into epochs. The core system does not only execute this workflow, it is also
 * self-contained in regard of the problem to be solved and the session to run.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   7.3.2019
 */
class EvolutionarySystem {

public:
    Representation &representation;

    explicit EvolutionarySystem(Representation &representation);

    /**
     * Initializes the population by performing the Initialization Operator on each individual concurrently.
     * @param pop     Population or state of the evolutionary system.
     * @param threads The initializing threads.
     */
    void initialize(Population &pop, std::vector<Thread> &threads) const;

    void evaluate(Population &pop, std::vector<Thread> &threads);
    void vary(Population &pop, std::vector<Thread> &threads);

};


#endif //RATATOSKR_EVOLUTIONARYSYSTEM_H
