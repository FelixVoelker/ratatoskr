#include <catch.hpp>
#include <iostream>

#include "../cc/toolbox/ec/ndga/NDGAProblem.h"
#include "../cc/toolbox/ec/ndga/NDGASession.h"
#include "../cc/toolbox/ec/ndga/BitVectorIndividual.h"
#include "../cc/toolbox/ec/ndga/FeatureVector.h"
#include "../core/variation/SelectionOperator.h"
#include "../cc/toolbox/ec/ndga/BitVectorMutation.h"
#include "../cc/toolbox/ec/ndga/BitVectorCrossover.h"


using namespace std;

/**
 * Unit tests for Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   1.8.2017
 */

class TestNDGAProblem : public NDGAProblem {

public:
    TestNDGAProblem(unsigned int pop_size, unsigned int genes) : NDGAProblem(pop_size, genes) {}

    void evaluate(Individual &individual) override {}
};

class IdentitySelectionOne : public SelectionOperator {

protected:
    vector<Individual *> select(Population &pop, Randomizer &random) override {
        vector<Individual *> selected(1);
        selected.at(0) = pop.getIndividuals().at(0);
        return selected;
    }

public:
    explicit IdentitySelectionOne(Session &session) : SelectionOperator(session) {}

};

class IdentitySelectionTwo : public SelectionOperator {

protected:
    vector<Individual *> select(Population &pop, Randomizer &random) override {
        vector<Individual *> selected(1);
        selected.at(0) = pop.getIndividuals().at(1);
        return selected;
    }

public:
    explicit IdentitySelectionTwo(Session &session) : SelectionOperator(session) {}

};

TEST_CASE("NDGA", "[ndga]") {
    auto problem = TestNDGAProblem(2, 8);
    auto session = NDGASession(problem);
    session.xover_rate = 1;
    session.mutation_rate = 1;

    Randomizer random = Randomizer();

    auto pop = Population(session);
    pop.initialize();
    vector<Individual *> &individuals = pop.getIndividuals();
    auto ind = (BitVectorIndividual *) individuals.at(0);
    vector<unsigned int> &chromosome = ind->getChromosome();
    chromosome.at(0) = 0;
    chromosome.at(1) = 1;
    chromosome.at(2) = 0;
    chromosome.at(3) = 1;
    chromosome.at(4) = 0;
    chromosome.at(5) = 0;
    chromosome.at(6) = 1;
    chromosome.at(7) = 1;
    SECTION("BitVectorIndividual") {
        SECTION("Checking human-readable representation...") {
            REQUIRE(ind->toString().compare("01010011") == 0);
        }
        SECTION("Checking cloning...") {
            auto copy = ind->clone();
            REQUIRE(&ind->getChromosome() != &copy->getChromosome());
            REQUIRE(equal(ind->getChromosome().begin(),
                          ind->getChromosome().end(),
                          copy->getChromosome().begin()));
            REQUIRE(equal(copy->getChromosome().begin(),
                          copy->getChromosome().end(),
                          ind->getChromosome().begin()));
        }
    }

    SECTION("FeatureVector") {
        FeatureVector &featuremap = dynamic_cast<FeatureVector &>(ind->getFeaturemap());
        SECTION("Checking features...") {
            vector<float> features = featuremap.compute(ind->getChromosome());
            REQUIRE(equal(features.begin(),
                          features.end(),
                          ind->getChromosome().begin()));
            REQUIRE(equal(ind->getChromosome().begin(),
                          ind->getChromosome().end(),
                          features.begin()));
        }
        SECTION("Checking cloning...") {
            FeatureVector *copy = featuremap.clone();
            REQUIRE(&featuremap != copy);
        }
    }

    SECTION("RandomBitVectorBuilder") {
        SECTION("Checking initialization...") {
            auto original = new vector<unsigned int>(chromosome);

            bool changed = false;

            for (int k = 1; k <= 10; k++) {
                pop.initialize();
                individuals = pop.getIndividuals();
                ind = dynamic_cast<BitVectorIndividual *>(individuals.at(0));
                chromosome = ind->getChromosome();
                if (!equal(original->begin(), original->end(), chromosome.begin())
                        && !equal(chromosome.begin(), chromosome.end(), original->begin())) {
                    changed = true;
                    break;
                }
            }

            REQUIRE(changed);
            delete original;
        }
    }

    SECTION("BitVectorCrossover") {
        SECTION("Check breed...") {
            auto parent1 = dynamic_cast<BitVectorIndividual *>(pop.getIndividuals().at(0));
            vector<unsigned int> &chromosome1 = parent1->getChromosome();
            chromosome1.at(0) = 1;
            chromosome1.at(1) = 1;
            chromosome1.at(2) = 1;
            chromosome1.at(3) = 1;
            chromosome1.at(4) = 1;
            chromosome1.at(5) = 1;
            chromosome1.at(6) = 1;
            chromosome1.at(7) = 1;
            auto parent2 = dynamic_cast<BitVectorIndividual *>(pop.getIndividuals().at(1));
            vector<unsigned int> &chromosome2 = parent2->getChromosome();
            chromosome2.at(0) = 0;
            chromosome2.at(1) = 0;
            chromosome2.at(2) = 0;
            chromosome2.at(3) = 0;
            chromosome2.at(4) = 0;
            chromosome2.at(5) = 0;
            chromosome2.at(6) = 0;
            chromosome2.at(7) = 0;

            vector<unsigned int> crossover_points = {0, 1, 2, 3, 4, 5, 6, 7};

            vector<VariationSource *> selectors(2);
            selectors.at(0) = new IdentitySelectionOne(session);
            selectors.at(1) = new IdentitySelectionTwo(session);
            BitVectorCrossover crossover = BitVectorCrossover(session);
            crossover.connect(selectors);

            for (int k = 1; k < 1000; k++) {
                vector<Individual *> offsprings = crossover.vary(pop, random);

                vector<unsigned int> &offspring1 = dynamic_cast<BitVectorIndividual *>(offsprings.at(0))->getChromosome();
                vector<unsigned int> &offspring2 = dynamic_cast<BitVectorIndividual *>(offsprings.at(1))->getChromosome();

                int cp;
                for (cp = 0; cp < offspring1.size(); cp++)  {
                    if (offspring1.at(cp) != chromosome.at(cp) && offspring2.at(cp) != chromosome2.at(cp))
                        break;
                }
                cp -= 1;

                bool crossed = true;
                for (int l = cp + 1; l < offspring1.size(); l++) {
                    crossed &= (offspring1.at(l) == chromosome2.at(l) && offspring2.at(l) == chromosome.at(l));
                }

                if (crossed) {
                    crossover_points.erase(remove(crossover_points.begin(), crossover_points.end(), cp), crossover_points.end());
                }

                offsprings.clear();
            }

            REQUIRE(crossover_points.size() == 0);
        }
    }

    SECTION("BitVectorMutation") {
        SECTION("Check breed...") {
            vector<VariationSource *> selector(1);
            selector.at(0) = new IdentitySelectionOne(session);
            BitVectorMutation mutation = BitVectorMutation(session);
            mutation.connect(selector);

            vector<Individual *> offsprings = mutation.vary(pop, random);
            vector<unsigned int> &mutant = dynamic_cast<BitVectorIndividual *>(offsprings.at(0))->getChromosome();

            for (int k = 0; k < chromosome.size(); k++) {
                chromosome.at(k) = 1 - chromosome.at(k);
            }

            REQUIRE(equal(chromosome.begin(),
                          chromosome.end(),
                          mutant.begin()));
            REQUIRE(equal(mutant.begin(),
                          mutant.end(),
                          chromosome.begin()));
        }
    }
}






