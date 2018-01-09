#include <catch.hpp>
#include "../core/representation/Individual.h"
#include "../core/util/Thread.h"
#include "../cc/common/Problem.h"
#include "../cc/common/FeatureVector.h"
#include "../cc/common/VectorIndividual.h"
#include "../core/representation/Population.h"
#include "../cc/common/FitnessProportionateSelection.h"

/**
 * Unit tests for common components of many Neuro-Dynamic Evolutionary Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   8.1.2018
 */
TEST_CASE("Common", "[common]") {
    std::function<void(Individual &, Thread &)> eval = [](Individual &individual, Thread &thread) {
        individual.getFitness().setFitness(1);
    };

    auto *problem = new common::Problem(eval, 3, 8);
    auto *configuration = new common::Configuration(dynamic_cast<common::Configuration::ProblemConfiguration &>(problem->getConfiguration()));

    auto *featurevector = new FeatureVector(*configuration);
    SECTION("FeatureVector") {
        SECTION("Checking features...") {
            std::vector<float> chromosome = {0, 1, 2};
            std::vector<float> features = featurevector->compute(chromosome);
            REQUIRE(equal(features.begin(),
                          features.end(),
                          chromosome.begin()));
            REQUIRE(equal(chromosome.begin(),
                          chromosome.end(),
                          features.begin()));
        }
    }

    auto *cost = new Cost(*configuration);
    auto *fitness = new Fitness(*configuration);
    auto *individual = new VectorIndividual(*configuration, cost, featurevector, fitness);
    SECTION("VectorIndividual") {
        individual->getChromosome().at(0) = 0;
        individual->getChromosome().at(1) = 1;
        individual->getChromosome().at(2) = 0;
        individual->getChromosome().at(3) = 1;
        individual->getChromosome().at(4) = 0;
        individual->getChromosome().at(5) = 0;
        individual->getChromosome().at(6) = 1;
        individual->getChromosome().at(7) = 1;

        SECTION("Checking human-readable bit vector representation...") {
            REQUIRE(individual->toString() == "01010011");
        }

        individual->getChromosome().at(0) = 40;
        individual->getChromosome().at(1) = 1.5;
        individual->getChromosome().at(2) = 0.5;
        individual->getChromosome().at(3) = 1.5;
        individual->getChromosome().at(4) = 0.5;
        individual->getChromosome().at(5) = 0.5;
        individual->getChromosome().at(6) = 1.5;
        individual->getChromosome().at(7) = 1.5;
        SECTION("Checking human-readable numerical vector representation...") {
            REQUIRE(individual->toString() == "(40.0, 1.5, 0.5, 1.5, 0.5, 0.5, 1.5, 1.5)");
        }

        SECTION("Checking cloning...") {
            auto *copy = individual->clone();
            REQUIRE(&individual->getChromosome() != &copy->getChromosome());
            REQUIRE(equal(individual->getChromosome().begin(),
                          individual->getChromosome().end(),
                          copy->getChromosome().begin()));
            REQUIRE(equal(copy->getChromosome().begin(),
                          copy->getChromosome().end(),
                          individual->getChromosome().begin()));
            delete copy;
        }
    }

    auto *pop = new Population(*configuration);
    pop->getIndividuals().at(0) = individual->clone();
    pop->getIndividuals().at(0)->getCost().setCost(10);
    pop->getIndividuals().at(0)->getFitness().setFitness(0);
    pop->getIndividuals().at(1) = individual->clone();
    pop->getIndividuals().at(1)->getCost().setCost(5);
    pop->getIndividuals().at(1)->getFitness().setFitness(5);
    pop->getIndividuals().at(2) = individual->clone();
    pop->getIndividuals().at(2)->getCost().setCost(0);
    pop->getIndividuals().at(2)->getFitness().setFitness(10);
    configuration->getEvolutionarySystemConfiguration().epochs = 2;
    auto *so = new FitnessProportionateSelection(*configuration);
    SECTION("FitnessProportionateSelection") {
        unsigned int epoch = 0;
        auto *thread = new Thread(0, 3, epoch);

        std::vector<unsigned int> counts = {0, 0, 0};

        Individual *selected;
        SECTION("Checking fitness based selection...") {
            for (unsigned int k = 1; k <= 1000; k++) {
                selected = so->select(pop->getIndividuals(), *thread);
                for (unsigned int l = 0; l < counts.size(); l++) {
                    if (selected == pop->getIndividuals().at(l)) {
                        counts.at(l) += 1;
                    }
                }
            }

            REQUIRE(counts.at(0) > counts.at(1));
            REQUIRE(counts.at(1) > counts.at(2));
        }

        epoch = 1;
        counts.at(0) = 0;
        counts.at(1) = 0;
        counts.at(2) = 0;
        SECTION("Checking average based selection...") {
            for (unsigned int k = 1; k <= 1000; k++) {
                selected = so->select(pop->getIndividuals(), *thread);
                for (unsigned int l = 0; l < counts.size(); l++) {
                    if (selected == pop->getIndividuals().at(l)) {
                        counts.at(l) += 1;
                    }
                }
            }

            unsigned int tolerance = 100;
            REQUIRE(counts.at(0) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(0) + tolerance);
            REQUIRE(counts.at(2) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(2) + tolerance);
        }

        epoch = 2;
        counts.at(0) = 0;
        counts.at(1) = 0;
        counts.at(2) = 0;
        SECTION("Checking cost based selection...") {
            for (unsigned int k = 1; k <= 1000; k++) {
                selected = so->select(pop->getIndividuals(), *thread);
                for (unsigned int l = 0; l < counts.size(); l++) {
                    if (selected == pop->getIndividuals().at(l)) {
                        counts.at(l) += 1;
                    }
                }
            }

            REQUIRE(counts.at(0) < counts.at(1));
            REQUIRE(counts.at(1) < counts.at(2));
        }

        delete thread;
    }

    delete so;
    delete pop;
    delete individual;
    delete configuration;
    delete problem;
}