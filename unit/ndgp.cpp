#include <catch.hpp>
#include "../cc/toolbox/ndgp/koza/KozaFitness.h"

/**
 * Unit tests for Neuro-Dynamic Genetic Programming.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   13.07.2017
 */

TEST_CASE("NDGP", "[ndgp]") {
    SECTION("KozaFitness") {
        KozaFitness koza1 = KozaFitness();
        koza1.setStandarizedFitness(5);

        KozaFitness koza2 = KozaFitness();
        koza2.setStandarizedFitness(5);

        KozaFitness koza3 = KozaFitness();
        koza3.setStandarizedFitness(0);

        SECTION("Checking optimality of getFitness...") {
            REQUIRE(!koza1.isIdeal());
            REQUIRE(!koza2.isIdeal());
            REQUIRE(koza3.isIdeal());
        }
        SECTION("Checking comparison of getFitness...") {
            REQUIRE(!(koza1 < koza2));
            REQUIRE(koza2 < koza3);
            REQUIRE(koza1 < koza3);

            REQUIRE(koza1 <= koza2);
            REQUIRE(koza2 <= koza3);
            REQUIRE(koza1 <= koza3);

            REQUIRE(koza1 == koza2);
            REQUIRE(!(koza2 == koza3));
            REQUIRE(!(koza1 == koza3));

            REQUIRE(koza1 >= koza2);
            REQUIRE(!(koza2 >= koza3));
            REQUIRE(!(koza1 >= koza3));

            REQUIRE(!(koza1 > koza2));
            REQUIRE(!(koza2 > koza3));
            REQUIRE(!(koza1 > koza3));
        }
    }
}