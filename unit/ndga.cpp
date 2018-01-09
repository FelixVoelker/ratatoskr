#include <catch.hpp>
#include <iostream>
#include "../cc/common/Problem.h"
#include "../cc/ndga/RandomBitVectorBuilder.h"
#include "../core/initialization/Initializer.h"

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

    auto *problem = new common::Problem(eval, 2, 3);
    auto *configuration = new common::Configuration(dynamic_cast<common::Configuration::ProblemConfiguration &>(problem->getConfiguration()));
//    session.xover_rate = 1;
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

    initializer->initializePopulation(*pop);

//    SECTION("BitVectorCrossover") {
//        SECTION("Check breed...") {
//            auto parent1 = dynamic_cast<BitVectorIndividual *>(pop.getIndividuals().at(0));
//            vector<unsigned int> &chromosome1 = parent1->getChromosome();
//            chromosome1.at(0) = 1;
//            chromosome1.at(1) = 1;
//            chromosome1.at(2) = 1;
//            chromosome1.at(3) = 1;
//            chromosome1.at(4) = 1;
//            chromosome1.at(5) = 1;
//            chromosome1.at(6) = 1;
//            chromosome1.at(7) = 1;
//            auto parent2 = dynamic_cast<BitVectorIndividual *>(pop.getIndividuals().at(1));
//            vector<unsigned int> &chromosome2 = parent2->getChromosome();
//            chromosome2.at(0) = 0;
//            chromosome2.at(1) = 0;
//            chromosome2.at(2) = 0;
//            chromosome2.at(3) = 0;
//            chromosome2.at(4) = 0;
//            chromosome2.at(5) = 0;
//            chromosome2.at(6) = 0;
//            chromosome2.at(7) = 0;
//
//            vector<unsigned int> crossover_points = {0, 1, 2, 3, 4, 5, 6, 7};
//
//            vector<VariationSource *> selectors(2);
//            selectors.at(0) = new IdentitySelectionOne(session);
//            selectors.at(1) = new IdentitySelectionTwo(session);
//            BitVectorCrossover crossover = BitVectorCrossover(session);
//            crossover.connect(selectors);
//
//            for (int k = 1; k < 1000; k++) {
//                vector<Individual *> offsprings = crossover.vary(pop, random);
//
//                vector<unsigned int> &offspring1 = dynamic_cast<BitVectorIndividual *>(offsprings.at(0))->getChromosome();
//                vector<unsigned int> &offspring2 = dynamic_cast<BitVectorIndividual *>(offsprings.at(1))->getChromosome();
//
//                int cp;
//                for (cp = 0; cp < offspring1.size(); cp++)  {
//                    if (offspring1.at(cp) != chromosome.at(cp) && offspring2.at(cp) != chromosome2.at(cp))
//                        break;
//                }
//                cp -= 1;
//
//                bool crossed = true;
//                for (int l = cp + 1; l < offspring1.size(); l++) {
//                    crossed &= (offspring1.at(l) == chromosome2.at(l) && offspring2.at(l) == chromosome.at(l));
//                }
//
//                if (crossed) {
//                    crossover_points.erase(remove(crossover_points.begin(), crossover_points.end(), cp), crossover_points.end());
//                }
//
//                offsprings.clear();
//            }
//
//            REQUIRE(crossover_points.size() == 0);
//        }
//    }
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

    delete initializer;
    delete pop;
    delete builder;
    delete configuration;
    delete problem;
}






