#ifndef RATATOSKR_CORE_CONFIGURATION_H
#define RATATOSKR_CORE_CONFIGURATION_H


namespace core {

/**
 * The base class for any configuration of a Neuro-Dynamic Evolutionary Algorithm (NDEA). These are specified by a
 * given problem configuration and a set of problem-independent parameters. Accordingly, any configuration corresponds
 * to a parameter database that is used to build any component of an evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   7.1.2018
 */
    class Configuration {

    public:
        /**
         * The configuration of the problem.
         * @param popsize Number of individuals within the population.
         */
        struct ProblemConfiguration {
            ProblemConfiguration() = default;
            ProblemConfiguration(const ProblemConfiguration &obj);
            virtual ~ProblemConfiguration() = default;

            unsigned int popsize = 0;
        };

        /**
         * The configuration of the evolutionary system.
         * @param complete    Determines whether an evolution progresses until the maximum generation.
         * @param epochs      Number of epochs to run.
         * @param episodes    Number of evolutions in each epoch.
         * @param generations Maximum number of generations to evolve.
         */
        struct EvolutionarySystemConfiguration {
            EvolutionarySystemConfiguration() = default;
            EvolutionarySystemConfiguration(const EvolutionarySystemConfiguration &obj);

            bool complete = false;
            unsigned int epochs = 10;
            unsigned int episodes = 100000;
            unsigned int generations = 200;
        };

        /**
         * The configuration of the initializer.
         * @param threads Number of used threads during initialization phase.
         */
        struct InitializerConfiguration {
            InitializerConfiguration() = default;
            InitializerConfiguration(const InitializerConfiguration &obj);

            unsigned int threads = 1;
        };

        /**
         * The configuration of the evaluator.
         * @param threads Number of used threads during evaluation phase.
         */
        struct EvaluatorConfiguration {
            EvaluatorConfiguration() = default;
            EvaluatorConfiguration(const EvaluatorConfiguration &obj);

            unsigned int threads = 1;
        };

        /**
         * The configuration of the breeder.
         * @param threads Number of used threads during variation phase.
         */
        struct BreederConfiguration {
            BreederConfiguration() = default;
            BreederConfiguration(const BreederConfiguration &obj);

            unsigned int threads = 1;
        };

        /**
         * The configuration of the evolutionary network.
         * @param discount_factor Factor of influence for delayed costs.
         * @param learning_rate The step size of the network's update rule.
         */
        struct EvolutionaryNetworkConfiguration {
            EvolutionaryNetworkConfiguration() = default;
            EvolutionaryNetworkConfiguration(const EvolutionaryNetworkConfiguration &obj);

            float discount_factor = 1;
            float learning_rate = 0.1;
        };

        explicit Configuration(ProblemConfiguration &problem);
        Configuration(const Configuration &obj);
        virtual ~Configuration() = default;

        ProblemConfiguration & getProblemConfiguration() const;
        EvolutionarySystemConfiguration & getEvolutionarySystemConfiguration();
        InitializerConfiguration & getInitializerConfiguration();
        EvaluatorConfiguration & getEvaluatorConfiguration();
        BreederConfiguration & getBreederConfiguration();
        EvolutionaryNetworkConfiguration & getEvolutionaryNetworkConfiguration();

    protected:
        ProblemConfiguration &problem;
        EvolutionarySystemConfiguration evolutionary_system;
        InitializerConfiguration initializer;
        EvaluatorConfiguration evaluator;
        BreederConfiguration breeder;
        EvolutionaryNetworkConfiguration evolutionary_network;

    };
}


#endif //RATATOSKR_CORE_CONFIGURATION_H
