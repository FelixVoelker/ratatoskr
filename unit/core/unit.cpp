#define CATCH_CONFIG_MAIN


#include <catch.hpp>
#include "../../core/representation/Fitness.h"
//#include "../../core/evaluation/Evaluator.h"
#include "util/SimpleProblem.h"
#include "util/SimpleSession.h"

/**
 * Unit tests for the core functionality of an evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   30.11.2017
 */
TEST_CASE("Core", "[core]") {
    auto problem = new SimpleProblem(1);
    auto session = new SimpleSession(*problem);
    SECTION("Fitness") {
        auto *f1 = new Fitness(*session);
        f1->setFitness(2);

        auto *f2 = new Fitness(*session);
        f2->setFitness(5);

        auto *f3 = new Fitness(*session);
        f3->setFitness(0);

        SECTION("Checking optimality of getFitness...") {
            REQUIRE(!f1->isIdeal());
            REQUIRE(!f2->isIdeal());
            REQUIRE(f3->isIdeal());
        }
        SECTION("Checking comparison of getFitness...") {
            REQUIRE(*f1 > *f2);
            REQUIRE(*f2 < *f3);
            REQUIRE(*f1 < *f3);
        }
    }
    /*SECTION("Problem") {
        auto task = new SimpleProblem(1);
        auto session = new SimpleSession(*task);
        auto pop = new Population(*session);
        SECTION("Evaluating an individual...") {
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            REQUIRE(pop->getIndividuals().at(0)->getRelevance().getFitness().fitness() == 1);
        }

        delete session;
        delete task;
    }
    SECTION("Evaluator") {
        auto task = new SimpleProblem(10);
        auto session = new SimpleSession(*task);
        SECTION("Checking evaluation...") {
            auto pop = new Population(*session);
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            bool all_ones = true;
            for (auto individual : pop->getIndividuals())
                all_ones &= individual->getRelevance().getFitness().setFitness() == 1;

            REQUIRE(all_ones);
        }

        SECTION("Checking multithreading...") {
            session->setEvalthreads(4);

            auto pop = new Population(*session);
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            bool all_ones = true;
            for (auto setIndividual : pop->getIndividuals())
                all_ones &= getIndividual->getRelevance().getFitness().getFitness() == 1;

            REQUIRE(all_ones);
        }

        delete session;
        delete task;
    }

    SECTION("VariationSource") {
        SECTION("Check initialization...") {
            bool initialized = false;
            vector<VariationSource *> sources(1);
            sources.at(0) = new FitnessProportionateSelection(*session);
            TestSource source = TestSource(*session);
            source.connect(sources);
            initialized = true;
            REQUIRE(initialized);
        }
    }*/

    delete session;
    delete problem;
}