#include <catch.hpp>
#include "../core/representation/Individual.h"
#include "../core/util/Thread.h"
#include "../cc/common/Problem.h"

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

}