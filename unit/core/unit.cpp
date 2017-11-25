#define CATCH_CONFIG_MAIN


#include <catch.hpp>
#include "../../core/evaluation/Evaluator.h"
#include "util/TestProblem.h"
#include "util/TestSession.h"

/**
 * Unit tests for Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
TEST_CASE("Core", "[core]") {
    SECTION("Problem") {
        auto task = new TestProblem(1);
        auto session = new TestSession(*task);
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
        auto task = new TestProblem(10);
        auto session = new TestSession(*task);
        SECTION("Checking evaluation...") {
            auto pop = new Population(*session);
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            bool all_ones = true;
            for (auto individual : pop->getIndividuals())
                all_ones &= individual->getRelevance().getFitness().fitness() == 1;

            REQUIRE(all_ones);
        }

        SECTION("Checking multithreading...") {
            session->evalthreads(4);

            auto pop = new Population(*session);
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            bool all_ones = true;
            for (auto individual : pop->getIndividuals())
                all_ones &= individual->getRelevance().getFitness().fitness() == 1;

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
    }

    delete session;
    delete problem;
}