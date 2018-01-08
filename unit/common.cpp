#include <catch.hpp>
#include "../core/representation/Individual.h"
#include "../core/util/Thread.h"
#include "../cc/common/Problem.h"
#include "../cc/common/FeatureVector.h"

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

    auto *problem = new common::Problem(eval, 1, 1);
    auto *configuration = new common::Configuration(dynamic_cast<common::Configuration::ProblemConfiguration &>(problem->getConfiguration()));

    SECTION("FeatureVector") {
        auto *featurevector = new FeatureVector(*configuration);

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

        delete featurevector;
    }

    delete configuration;
    delete problem;
}