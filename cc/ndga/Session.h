#ifndef RATATOSKR_NDGA_SESSION_H
#define RATATOSKR_NDGA_SESSION_H


#include "../../core/Session.h"
#include "../common/Problem.h"
#include "RandomBitVectorBuilder.h"
#include "../common/TransitionTable.h"
#include "BitVectorMutation.h"

namespace ndga {

    /**
     * The session for conventional and modified Neuro-Dynamic Genetic Algorithms (NDGAs).
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   25.1.2018
     */
    class Session : public core::Session {

    public:
        explicit Session(const common::Problem &problem);
        explicit Session(const common::Problem &problem, common::Configuration *config);

        /**
         * Sets up the evolutionary system for a conventional NDGA.
         */
        EvolutionarySystem * build();

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary builder.
         * @param builder The bit vector builder of the evolutionary system's vector individuals.
         */
        EvolutionarySystem * build(RandomBitVectorBuilder *builder);

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary evolutionary network.
         * @param network The cost approximating evolutionary network.
         */
        EvolutionarySystem * build(TransitionTable *network);

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary variation tree.
         * @param variation_tree The offspring breeding variation tree.
         */
        EvolutionarySystem * build(BreedingOperator *variation_tree);

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary builder and evolutionary network.
         * @param builder The bit vector builder of the evolutionary system's vector individuals.
         * @param network The cost approximating evolutionary network.
         */
        EvolutionarySystem * build(RandomBitVectorBuilder *builder, TransitionTable *network);

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary builder and variation tree.
         * @param builder The bit vector builder of the evolutionary system's vector individuals.
         * @param variation_tree The offspring breeding variation tree.
         */
        EvolutionarySystem * build(RandomBitVectorBuilder *builder, BreedingOperator *variation_tree);

        /**
         * Sets up the evolutionary system for a NDGA with an arbitrary evolutionary network and variation tree.
         * @param network The cost approximating evolutionary network.
         * @param variation_tree The offspring breeding variation tree.
         */
        EvolutionarySystem * build(TransitionTable *network, BreedingOperator *variation_tree);

    protected:
        /**
         * Constructs the builder for conventional NDGAs.
         */
        RandomBitVectorBuilder * constructDefaultBuilder();

        /**
         * Constructs the evolutionary network for conventional NDGAs.
         */
        TransitionTable * constructDefaultNetwork();

        /**
         * Constructs the variation tree for conventional NDGAs.
         */
        BitVectorMutation * constructDefaultVariation();

    };
}


#endif //RATATOSKR_NDGA_SESSION_H
