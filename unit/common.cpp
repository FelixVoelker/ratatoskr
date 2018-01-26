#include <catch.hpp>
#include "../core/representation/Individual.h"
#include "../core/util/Thread.h"
#include "../cc/common/Problem.h"
#include "../cc/common/FeatureVector.h"
#include "../cc/common/VectorIndividual.h"
#include "../core/representation/Population.h"
#include "../cc/common/FitnessProportionateSelection.h"
#include "util/SimpleEvaluationFunction.h"

/**
 * Unit tests for common components of many Neuro-Dynamic Evolutionary Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
TEST_CASE("Common", "[common]") {
    auto *eval = new SimpleEvaluationFunction();
    auto *problem = new common::Problem(*eval, 3, 8);
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

    auto *relevance = new Relevance(*configuration);
    auto *individual = new VectorIndividual(*configuration, *featurevector, *relevance);
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

    delete featurevector;
    delete relevance;

    auto *pop = new Population(*configuration);
    pop->getIndividuals().at(0) = individual->clone();
    pop->getIndividuals().at(0)->getRelevance().setCost(10);
    pop->getIndividuals().at(0)->getRelevance().setFitness(0);
    pop->getIndividuals().at(1) = individual->clone();
    pop->getIndividuals().at(1)->getRelevance().setCost(5);
    pop->getIndividuals().at(1)->getRelevance().setFitness(5);
    pop->getIndividuals().at(2) = individual->clone();
    pop->getIndividuals().at(2)->getRelevance().setCost(0);
    pop->getIndividuals().at(2)->getRelevance().setFitness(10);
    configuration->getEvolutionarySystemConfiguration().epochs = 2;
    SECTION("FitnessProportionateSelection") {
        auto *so = new FitnessProportionateSelection(*configuration);

        unsigned int epoch = 0;
        auto *thread = new Thread(0, 3);

        std::vector<unsigned int> counts = {0, 0, 0};

        Individual *selected;
        SECTION("Checking fitness based selection...") {
            pop->getIndividuals().at(0)->getRelevance().setFraction(0);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0);

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

        counts.at(0) = 0;
        counts.at(1) = 0;
        counts.at(2) = 0;
        SECTION("Checking average based selection...") {
            pop->getIndividuals().at(0)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0.5);

            for (unsigned int k = 1; k <= 1000; k++) {
                selected = so->select(pop->getIndividuals(), *thread);
                for (unsigned int l = 0; l < counts.size(); l++) {
                    if (selected == pop->getIndividuals().at(l)) {
                        counts.at(l) += 1;
                    }
                }
            }

            unsigned int tolerance = 100;
            for (unsigned int k = 0; k < counts.size() - 1; k++) {
                if (counts.at(k) >= tolerance) {
                    REQUIRE(counts.at(k) - tolerance <= counts.at(k + 1));
                }
                REQUIRE(counts.at(k + 1) <= counts.at(k) + tolerance);
            }
        }

        counts.at(0) = 0;
        counts.at(1) = 0;
        counts.at(2) = 0;
        SECTION("Checking cost based selection...") {
            pop->getIndividuals().at(0)->getRelevance().setFraction(1);
            pop->getIndividuals().at(1)->getRelevance().setFraction(1);
            pop->getIndividuals().at(2)->getRelevance().setFraction(1);

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
        delete so;
    }


    delete pop;
    delete individual;
    delete configuration;
    delete problem;
    delete eval;
}