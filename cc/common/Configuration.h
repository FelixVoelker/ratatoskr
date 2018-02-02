#ifndef RATATOSKR_COMMON_CONFIGURATION_H
#define RATATOSKR_COMMON_CONFIGURATION_H


#include "../../core/Configuration.h"

namespace common {

    /**
     * A configuration for several types of Neuro-Dynamic Evolutionary Algorithms (NDEAs).
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   25.1.2018
     */
    class Configuration : public core::Configuration {

    public:
        /**
         * The configuration of common problems.
         * @param genes Number of genes in a chromosome.
         */
        struct ProblemConfiguration : core::Configuration::ProblemConfiguration {
            ProblemConfiguration();
            ProblemConfiguration(const ProblemConfiguration &obj);

            unsigned int genes;
        };

        struct CrossoverConfiguration {
            CrossoverConfiguration() = default;
            CrossoverConfiguration(const CrossoverConfiguration &obj);

            float xover_rate = 0.7f;
        };

        struct MutationConfiguration {
            MutationConfiguration() = default;
            MutationConfiguration(const MutationConfiguration &obj);

            float mutation_rate = 0.001f;
        };

        explicit Configuration(const ProblemConfiguration &problem);
        Configuration(const Configuration &obj) = default;

        CrossoverConfiguration & getCrossoverConfiguration();
        const CrossoverConfiguration & getCrossoverConfiguration() const;
        MutationConfiguration & getMutationConfiguration();
        const MutationConfiguration & getMutationConfiguration() const;

    protected:
        CrossoverConfiguration crossover;
        MutationConfiguration mutation;

    };
}


#endif //RATATOSKR_COMMON_CONFIGURATION_H
