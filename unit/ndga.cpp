#include <catch.hpp>
#include <iostream>
#include "../cc/common/Problem.h"
#include "../cc/ndga/RandomBitVectorBuilder.h"
#include "../core/initialization/Initializer.h"
#include "../cc/common/FitnessProportionateSelection.h"
#include "../cc/ndga/BitVectorCrossover.h"

/**
 * Unit tests for Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.1.2018
 */
TEST_CASE("NDGA", "[ndga]") {
    std::function<void(Individual &, Thread &)> eval = [](Individual &individual, Thread &thread) {
        individual.getFitness().setFitness(1);
    };

    unsigned int genes = 3;
    auto *problem = new common::Problem(eval, 2, genes);
    auto *configuration = new common::Configuration(dynamic_cast<common::Configuration::ProblemConfiguration &>(problem->getConfiguration()));
//    session.mutation_rate = 1;


    auto *cost = new Cost(*configuration);
    auto *featurevector = new FeatureVector(*configuration);
    auto *fitness = new Fitness(*configuration);
    auto *prototype = new VectorIndividual(*configuration, cost, featurevector, fitness);
    auto *builder = new RandomBitVectorBuilder(*configuration, prototype);
    auto *pop = new Population(*configuration);

    unsigned int epoch = 0;
    auto *initializer = new Initializer(*configuration, builder, epoch);
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
            REQUIRE(counts.at(0) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(0) + tolerance);
            REQUIRE(counts.at(2) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(2) + tolerance);
        }
    }

    auto *thread = new Thread(0, 2, epoch);
    initializer->initializePopulation(*pop);
    configuration->getCrossoverConfiguration().xover_rate = 1;

    auto *crossover = new BitVectorCrossover(*configuration);
    std::vector<VariationSource *> sources = {
            new FitnessProportionateSelection(*configuration),
            new FitnessProportionateSelection(*configuration)
    };
    sources.at(0)->setup(*new std::vector<VariationSource *>(0));
    sources.at(1)->setup(*new std::vector<VariationSource *>(0));
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
//
//    SECTION("BitVectorMutation") {
//        SECTION("Check breed...") {
//            vector<VariationSource *> selector(1);
//            selector.at(0) = new IdentitySelectionOne(session);
//            BitVectorMutation mutation = BitVectorMutation(session);
//            mutation.connect(selector);
//
//            vector<Individual *> offsprings = mutation.vary(pop, random);
//            vector<unsigned int> &mutant = dynamic_cast<BitVectorIndividual *>(offsprings.at(0))->getChromosome();
//
//            for (int k = 0; k < chromosome.size(); k++) {
//                chromosome.at(k) = 1 - chromosome.at(k);
//            }
//
//            REQUIRE(equal(chromosome.begin(),
//                          chromosome.end(),
//                          mutant.begin()));
//            REQUIRE(equal(mutant.begin(),
//                          mutant.end(),
//                          chromosome.begin()));
//        }
//    }

    delete crossover;
    delete initializer;
    delete pop;
    delete builder;
    delete configuration;
    delete problem;
}






