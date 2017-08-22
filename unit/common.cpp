#include <catch.hpp>
#include "../cc/toolbox/ec/common/RawFitness.h"
#include "../cc/toolbox/ec/ndga/NDGASession.h"
#include "TestComponents.h"

/**
 * Unit tests for common components.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   1.8.2017
 */
TEST_CASE("Common", "[common]") {
    TestProblem problem = TestProblem();
    TestSession session = TestSession(problem);
    SECTION("RawFitness") {
        RawFitness fitness1 = RawFitness(session);
        fitness1.setFitness(5);
        fitness1.setHits(0);

        RawFitness fitness2 = RawFitness(session);
        fitness2.setFitness(5);
        fitness2.setHits(1);

        RawFitness fitness3 = RawFitness(session);
        fitness3.setFitness(0);
        fitness3.setHits(2);

        SECTION("Checking optimality of fitness...") {
            REQUIRE(fitness1.isIdeal());
            REQUIRE(!fitness2.isIdeal());
            REQUIRE(!fitness3.isIdeal());
        }
        SECTION("Checking comparison of fitness...") {
            REQUIRE(!(fitness1 < fitness2));
            REQUIRE(!(fitness2 < fitness3));
            REQUIRE(!(fitness1 < fitness3));

            REQUIRE(fitness1 <= fitness2);
            REQUIRE(!(fitness2 <= fitness3));
            REQUIRE(!(fitness1 <= fitness3));

            REQUIRE(fitness1 == fitness2);
            REQUIRE(!(fitness2 == fitness3));
            REQUIRE(!(fitness1 == fitness3));

            REQUIRE(fitness1 >= fitness2);
            REQUIRE(fitness2 >= fitness3);
            REQUIRE(fitness1 >= fitness3);

            REQUIRE(!(fitness1 > fitness2));
            REQUIRE(fitness2 > fitness3);
            REQUIRE(fitness1 > fitness3);
        }
    }
}