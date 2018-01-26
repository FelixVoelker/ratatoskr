#ifndef RATATOSKR_CORE_SESSION_H
#define RATATOSKR_CORE_SESSION_H


#include "Problem.h"
#include "EvolutionarySystem.h"

namespace core {

    /**
     * The base class for any Neuro-Dynamic Evolutionary Algorithm (NDEA) that can be run. A session builds the
     * evolutionary system of the desired method by setting up all necessary parameters for every component. It requires
     * the problem to be solved in order to extract the problem-dependent specifications. However, it hides all method
     * specific parameters to make the building process more convenient.
     *
     * @author  FelixVoelker
     * @version 0.1.0
     * @since   25.1.2018
     */
    class Session {

    public:
        explicit Session(const Problem &problem);
        explicit Session(const Problem &problem, core::Configuration *config);
        ~Session();

        /**
         * Sets up the evolutionary system for an arbitrary NDEA.
         * @param builder The builder of the evolutionary system's individuals.
         * @param network The cost approximating evolutionary network.
         * @param variation_tree The offspring breeding variation tree.
         */
        EvolutionarySystem * build(Builder &builder,
                                  EvolutionaryNetwork &network,
                                  BreedingOperator &variation_tree);

        Configuration & getConfiguration();

    protected:
        const Problem &problem;
        Configuration *configuration;

    };
}


#endif //RATATOSKR_CORE_SESSION_H
