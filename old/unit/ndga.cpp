#include <catch.hpp>
#include <iostream>
#include "../cc/common/Problem.h"
#include "../cc/representation/vector/binary/RandomBinaryVectorBuilder.h"
#include "../core/initialization/Initializer.h"
#include "../cc/selection/FitnessProportionateSelection.h"
#include "../cc/representation/vector/binary/BinaryVectorCrossover.h"
#include "../cc/representation/vector/binary/BinaryVectorMutation.h"
#include "../cc/ndga/Session.h"
#include "../cc/ndga/EvaluationFunctions.h"
#include "util/SimpleEvaluationFunction.h"

/**
 * Unit tests for Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   25.1.2018
 */
TEST_CASE("NDGA", "[ndga]") {
    auto *eval = new SimpleEvaluationFunction();

    unsigned int genes = 3;
    auto *problem = new common::Problem(*eval, 2, genes);
    auto *configuration = new common::Configuration(dynamic_cast<common::Configuration::ProblemConfiguration &>(problem->getConfiguration()));

    auto *featurevector = new FeatureVector(*configuration);
    auto *relevance = new Relevance(*configuration);
    auto *prototype = new VectorIndividual(*configuration, *featurevector, *relevance);
    auto *builder = new RandomBinaryVectorBuilder(*configuration, *prototype);
    auto *pop = new Population(*configuration);

    delete featurevector;
    delete relevance;
    delete prototype;

    unsigned int epoch = 0;
    auto *initializer = new Initializer(*configuration, *builder, epoch);
    SECTION("RandomBitVectorBuilder") {
        SECTION("Checking initialization...") {
            std::vector<unsigned int> counts(8, 0);
            for (unsigned int k = 1; k <= 1000; k++) {
                initializer->initializePopulation(*pop);
                std::vector<float> &chromosome = dynamic_cast<VectorIndividual *>(pop->getIndividuals().at(0))->getChromosome();

                unsigned int index = 0;
                for (unsigned int l = 0; l < chromosome.size(); l++) {
                    index += static_cast<unsigned int>(chromosome.at(chromosome.size() - 1 - l)) * pow(2, l);
                }

                counts.at(index) += 1;
            }

            unsigned int tolerance = 100;
            for (unsigned int k = 0; k < counts.size() - 1; k++) {
                if (counts.at(k) >= tolerance) {
                    REQUIRE(counts.at(k) - tolerance <= counts.at(k + 1));
                }
                REQUIRE(counts.at(k + 1) <= counts.at(k) + tolerance);
            }
        }
    }

    delete builder;

    auto *thread = new Thread(0, 2);
    initializer->initializePopulation(*pop);

    configuration->getCrossoverConfiguration().xover_rate = 1.0;
    auto *crossover = new BinaryVectorCrossover(*configuration);
    std::vector<VariationSource *> *sources = new std::vector<VariationSource *>({
            new FitnessProportionateSelection(*configuration),
            new FitnessProportionateSelection(*configuration)
    });
    sources->at(0)->setup(new std::vector<VariationSource *>(0));
    sources->at(1)->setup(new std::vector<VariationSource *>(0));
    crossover->setup(sources);
    SECTION("BitVectorCrossover") {
        SECTION("Checking breeding...") {
            std::vector<Individual *> parents = pop->getIndividuals();
            std::vector<float> &parent1 = dynamic_cast<VectorIndividual *>(parents.at(0))->getChromosome();
            parent1.at(0) = 1;
            parent1.at(1) = 1;
            parent1.at(2) = 1;
            std::vector<float> &parent2 = dynamic_cast<VectorIndividual *>(parents.at(1))->getChromosome();
            parent2.at(0) = 0;
            parent2.at(1) = 0;
            parent2.at(2) = 0;

            std::vector<bool> used = {false, false, false};
            for (int k = 1; k <= 10000; k++) {
                std::vector<Individual *> offsprings = crossover->vary(parents, *thread);

                std::vector<float> &offspring1 = dynamic_cast<VectorIndividual *>(offsprings.at(0))->getChromosome();
                std::vector<float> &offspring2 = dynamic_cast<VectorIndividual *>(offsprings.at(1))->getChromosome();

                if (offspring1.at(0) == 0 && offspring2.at(1) == 1) {
                    auto o = std::vector<float>(offspring1);
                    offspring1 = offspring2;
                    offspring2 = o;
                }

                unsigned int crossover_point = 0;
                for (unsigned int cp = 0; cp < genes; cp++)  {
                    if ((parent1.at(cp) != offspring1.at(cp) && parent2.at(cp) != offspring2.at(cp))) {
                        break;
                    }
                    crossover_point += 1;
                }
                crossover_point -= 1;

                bool crossed = true;
                for (unsigned int cp = crossover_point + 1; cp < genes; cp++) {
                    crossed &= (parent1.at(cp) == offspring2.at(cp) && parent2.at(cp) == offspring1.at(cp));
                }

                if (crossed) {
                    if (crossover_point == -1) {
                        break;
                    }
                    used.at(crossover_point) = true;
                }

                delete offsprings.at(0);
                delete offsprings.at(1);
            }

            REQUIRE(used.at(0));
            REQUIRE(used.at(1));
            REQUIRE(used.at(2));
        }
    }

    delete crossover;

    configuration->getMutationConfiguration().mutation_rate = 1.0;
    auto *mutation = new BinaryVectorMutation(*configuration);
    sources = new std::vector<VariationSource *> {
            new FitnessProportionateSelection(*configuration)
    };
    sources->at(0)->setup(new std::vector<VariationSource *>(0));
    mutation->setup(sources);
    SECTION("BitVectorMutation") {
        SECTION("Checking breeding...") {
            auto &parent1 = dynamic_cast<VectorIndividual *>(pop->getIndividuals().at(0))->getChromosome();
            auto &parent2 = dynamic_cast<VectorIndividual *>(pop->getIndividuals().at(1))->getChromosome();

            std::vector<Individual *> offsprings = mutation->vary(pop->getIndividuals(), *thread);
            auto &offspring = dynamic_cast<VectorIndividual *>(offsprings.at(0))->getChromosome();
            for (unsigned int k = 0; k < genes; k++) {
                offspring.at(k) = 1 - offspring.at(k);
            }

            if (parent1 != offspring) {
                REQUIRE(parent2 == offspring);
            } else {
                REQUIRE(parent1 == offspring);
            }
        }
    }

    delete mutation;
    delete pop;
    delete initializer;

    SECTION("EvaluationFunctions") {
        SECTION("Checking OneMaxProblem...") {
            auto *e = ndga::EvaluationFunctions::evalOneMax();
            auto *p =  new common::Problem(*e, 200, 20);
            auto *session = new ndga::Session(*p);
            session->getConfiguration().getEvolutionarySystemConfiguration().epochs = 1;
            session->getConfiguration().getEvolutionarySystemConfiguration().episodes = 1;
            session->getConfiguration().getEvolutionarySystemConfiguration().generations = 200;
            auto *system = session->build();

            system->run();
            auto & statistics = system->getStatistics();
            REQUIRE(statistics.bestFitness(0).at(200) == 0);

            delete system;
            delete session;
            delete p;
            delete e;
        }
    }

    delete configuration;
    delete problem;
    delete eval;
}






