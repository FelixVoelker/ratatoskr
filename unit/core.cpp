#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "TestComponents.h"
#include "../core/evaluation/Evaluator.h"
#include "../cc/toolbox/ec/common/FitnessProportionateSelection.h"
#include "../cc/toolbox/ec/common/RawFitness.h"


/**
 * Unit tests for the core system.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   6.8.2017
 */
TEST_CASE("Core", "[core]") {
    auto problem = new TestProblem();
    auto session = new TestSession(*problem);
    SECTION("Evaluator") {
        SECTION("Check multithreading...") {
            session->evalthreads = 4;
            auto pop = new Population(*session);
            pop->initialize();

            auto evaluator = new Evaluator(*session);
            evaluator->evaluatePopulation(*pop);

            bool all_ones = true;

            vector<Individual *> &individuals = pop->getIndividuals();
            for (int k = 0; k < individuals.size(); k++) {
                all_ones &= dynamic_cast<RawFitness &>(individuals.at(k)->getFitness()).getFitness() == 1;
            }

            REQUIRE(all_ones);
        }
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

}