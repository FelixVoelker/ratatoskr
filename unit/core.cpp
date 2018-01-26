#define CATCH_CONFIG_MAIN


#include <catch.hpp>
#include "util/SimpleBuilder.h"
#include "../core/representation/Population.h"
#include "util/SimpleVariationSource.h"
#include "util/SimpleIndividual.h"
#include "util/SimpleSelectionOperator.h"
#include "util/SimpleBreedingOperator.h"
#include "../core/initialization/Initializer.h"
#include "../core/evaluation/Evaluator.h"
#include "../core/variation/Breeder.h"
#include "../core/statistics/Statistics.h"
#include "../core/EvolutionarySystem.h"
#include "util/SimpleFeatureMap.h"
#include "util/SimpleEvolutionaryNetwork.h"
#include "../core/Problem.h"
#include "../core/Session.h"
#include "util/SimpleEvaluationFunction.h"

using namespace core;

/**
 * Unit tests for the core functionality of an evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
TEST_CASE("Core", "[core]") {
    auto *eval = new SimpleEvaluationFunction();
    auto *problem = new Problem(*eval, 1);
    auto *session = new Session(*problem);
    auto &configuration = session->getConfiguration();

    SECTION("Relevance") {
        auto *r1 = new Relevance(configuration);
        r1->setFraction(-1);
        r1->setCost(0);
        r1->setFitness(9);
        auto *r2 = new Relevance(configuration);
        r2->setFraction(0.5);
        r2->setCost(2.5);
        r2->setFitness(7.5);
        auto *r3 = new Relevance(configuration);
        r3->setFraction(2);
        r3->setCost(5);
        r3->setFitness(0);

        SECTION("Checking computation of error...") {
            REQUIRE(r1->error(1, 0.5, 0) == 0.5);
            REQUIRE(r2->error(1, 0.5, 2) == 0);
            REQUIRE(r3->error(1, 0.5, 0) == -4.5);
        }

        SECTION("Checking optimality of fitnesses...") {
            REQUIRE(!r1->isIdeal());
            REQUIRE(!r2->isIdeal());
            REQUIRE(r3->isIdeal());
        }

        SECTION("Checking computation of relevance...") {
            REQUIRE(r1->relevance() == 9.0f);
            REQUIRE(r2->relevance() == 5.0f);
            REQUIRE(r3->relevance() == 5.0f);
        }

        SECTION("Checking computation of adjusted relevance...") {
            REQUIRE(r1->adjustedRelevance() == 0.1f);
            REQUIRE(r2->adjustedRelevance() == 1.0f / 6.0f);
            REQUIRE(r3->adjustedRelevance() == 1.0f / 6.0f);
        }

        SECTION("Checking comparison of relevances...") {
            r1->setFraction(-1);
            r2->setFraction(-1);
            r3->setFraction(-1);
            REQUIRE(*r1 < *r2);
            REQUIRE(*r2 < *r3);
            r1->setFraction(0.5);
            r2->setFraction(0.5);
            r3->setFraction(0.5);
            REQUIRE(*r1 > *r2);
            REQUIRE(*r2 < *r3);
            r1->setFraction(2);
            r2->setFraction(2);
            r3->setFraction(2);
            REQUIRE(*r1 > *r2);
            REQUIRE(*r2 > *r3);
        }

        SECTION("Checking cloning...") {
            auto *rc = r1->clone();
            REQUIRE(rc != r1);
            REQUIRE(rc->getCost() == r1->getCost());
            REQUIRE(rc->getFitness() == r1->getFitness());
            delete rc;
        }

        delete r1;
        delete r2;
        delete r3;
    }

    auto *featuremap = new SimpleFeatureMap(configuration);
    auto *relevance = new Relevance(configuration);
    auto *individual = new SimpleIndividual(configuration, *featuremap, *relevance);
    SECTION("Individual") {
        individual->getRelevance().setFitness(2.5);
        individual->getRelevance().setCost(5);

        SECTION("Checking cloning...") {
            auto *copy = individual->clone();
            REQUIRE(individual != copy);
            REQUIRE(individual->getRelevance().getCost() == copy->getRelevance().getCost());
            REQUIRE(individual->getRelevance().getFitness() == copy->getRelevance().getFitness());
            delete copy;
        }
    }

    delete featuremap;
    delete relevance;

    unsigned int epoch = 0;
    auto *thread = new Thread(0, 3);
    SECTION("Thread") {
        SECTION("Checking sampling from uniform distribution...") {
            std::vector<unsigned int> counts = std::vector<unsigned int>(3);
            counts.at(0) = 0;
            counts.at(1) = 0;
            counts.at(2) = 0;

            for (unsigned int k = 1; k <= 1000; k++) {
                counts.at(thread->random.sampleIntFromUniformDistribution(3)) += 1;
            }

            unsigned int tolerance = 100;
            for (unsigned int k = 0; k < counts.size() - 1; k++) {
                if (counts.at(k) >= tolerance) {
                    REQUIRE(counts.at(k) - tolerance <= counts.at(k + 1));
                }
                REQUIRE(counts.at(k + 1) <= counts.at(k) + tolerance);
            }
        }

        SECTION("Checking sampling from discrete distribution...") {
            std::vector<float> weights = std::vector<float>(3);
            weights.at(0) = 10;
            weights.at(1) = 5;
            weights.at(2) = 1;

            std::vector<unsigned int> counts = std::vector<unsigned int>(3);
            counts.at(0) = 0;
            counts.at(1) = 0;
            counts.at(2) = 0;

            for (unsigned int k = 1; k <= 1000; k++) {
                counts.at(thread->random.sampleIntFromDiscreteDistribution(weights)) += 1;
            }

            REQUIRE(counts.at(0) > counts.at(1));
            REQUIRE(counts.at(1) > counts.at(2));
        }
    }

    auto *builder = new SimpleBuilder(configuration, *individual);
    SECTION("Builder") {
        auto *ind = builder->build(*thread);

        SECTION("Checking initialization...") {
            REQUIRE(ind->toString() == "passed");
        }

        delete ind;
    }

    delete individual;

    problem->getConfiguration().popsize = 3;
    auto *pop = new Population(configuration);
    SECTION("Population") {
        pop->getIndividuals().at(0) = builder->build(*thread);
        pop->getIndividuals().at(1) = builder->build(*thread);
        pop->getIndividuals().at(2) = builder->build(*thread);

        SECTION("Checking extermination...") {
            pop->exterminate();
            for (auto ind : pop->getIndividuals()) {
                REQUIRE(ind == nullptr);
            }
        }

        pop->getIndividuals().at(0) = builder->build(*thread);
        pop->getIndividuals().at(0)->getRelevance().setCost(0);
        pop->getIndividuals().at(0)->getRelevance().setFitness(0);
        pop->getIndividuals().at(1) = builder->build(*thread);
        pop->getIndividuals().at(1)->getRelevance().setCost(3);
        pop->getIndividuals().at(1)->getRelevance().setFitness(5);
        pop->getIndividuals().at(2) = builder->build(*thread);
        pop->getIndividuals().at(2)->getRelevance().setCost(7.5);
        pop->getIndividuals().at(2)->getRelevance().setFitness(2.5);

        SECTION("Finding the best individual...") {
            pop->getIndividuals().at(0)->getRelevance().setFraction(0);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0);
            REQUIRE(pop->bestIndividual() == pop->getIndividuals().at(0));
            pop->getIndividuals().at(0)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0.5);
            REQUIRE(pop->bestIndividual() == pop->getIndividuals().at(0));
            pop->getIndividuals().at(0)->getRelevance().setFraction(1);
            pop->getIndividuals().at(1)->getRelevance().setFraction(1);
            pop->getIndividuals().at(2)->getRelevance().setFraction(1);
            REQUIRE(pop->bestIndividual() == pop->getIndividuals().at(0));
        }

        SECTION("Finding the worst individual...") {
            pop->getIndividuals().at(0)->getRelevance().setFraction(0);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0);
            REQUIRE(pop->worstIndividual() == pop->getIndividuals().at(1));
            pop->getIndividuals().at(0)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(1)->getRelevance().setFraction(0.5);
            pop->getIndividuals().at(2)->getRelevance().setFraction(0.5);
            REQUIRE(pop->worstIndividual() == pop->getIndividuals().at(2));
            pop->getIndividuals().at(0)->getRelevance().setFraction(1);
            pop->getIndividuals().at(1)->getRelevance().setFraction(1);
            pop->getIndividuals().at(2)->getRelevance().setFraction(1);
            REQUIRE(pop->worstIndividual() == pop->getIndividuals().at(2));
        }

        SECTION("Computing the average individual...") {
            auto *average = pop->averageIndividual();
            average->getRelevance().setFraction(0.5);
            REQUIRE(average->getRelevance().getCost() == 10.5 / 3);
            REQUIRE(average->getRelevance().getFitness() == 7.5f / 3);
            REQUIRE(average->getRelevance().relevance() == 9.0f / 3);
            delete average;
        }
    }

    configuration.getInitializerConfiguration().threads = 2;
    auto *initializer = new Initializer(configuration, *builder, epoch);
    initializer->initializePopulation(*pop);
    SECTION("Initializer") {
        SECTION("Initializating a population...") {
            REQUIRE(pop->getIndividuals().at(0)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(1)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(2)->toString() == "passed");
        }
    }

    delete initializer;

    configuration.getEvaluatorConfiguration().threads = 2;
    auto *network = new SimpleEvolutionaryNetwork(configuration);
    auto *evaluator = new Evaluator(configuration, *eval, *network);
    SECTION("Evaluator") {
        SECTION("Evaluating a population...") {
            evaluator->evaluatePopulation(*pop);
            evaluator->evaluatePopulation(*pop);
            REQUIRE(pop->getIndividuals().at(0)->getRelevance().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(1)->getRelevance().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(2)->getRelevance().getFitness() == 1);
        }
    }

    delete evaluator;

    SECTION("VariationSource") {
        auto *vs = new SimpleVariationSource(configuration);
        vs->setup(new std::vector<VariationSource *>(0));

        SECTION("Checking workflow...") {
            std::vector<Individual *> parents = pop->getIndividuals();
            std::vector<Individual *> offsprings = vs->vary(parents, *thread);
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "bred");
        }

        delete vs;
    }

    auto *so = new SimpleSelectionOperator(configuration);
    so->setup(new std::vector<VariationSource *>(0));
    SECTION("SelectionOperator") {
        SECTION("Checking selection...") {
            std::vector<Individual *> parents = pop->getIndividuals();
            dynamic_cast<SimpleIndividual *>(parents.at(0))->setLabel("first");
            dynamic_cast<SimpleIndividual *>(parents.at(1))->setLabel("second");
            dynamic_cast<SimpleIndividual *>(parents.at(2))->setLabel("third");
            std::vector<Individual *> offsprings = so->vary(parents, *thread);
            REQUIRE(offsprings.size() == 1);
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "first");
        }
    }

    auto *bo = new SimpleBreedingOperator(configuration);
    bo->setup(new std::vector<VariationSource *>({ so }));
    SECTION("BreedingOperator") {
        SECTION("Checking breeding...") {
            std::vector<Individual *> parents = pop->getIndividuals();
            dynamic_cast<SimpleIndividual *>(parents.at(0))->setLabel("first");
            dynamic_cast<SimpleIndividual *>(parents.at(1))->setLabel("second");
            dynamic_cast<SimpleIndividual *>(parents.at(2))->setLabel("third");
            std::vector<Individual *> offsprings = bo->vary(parents, *thread);
            REQUIRE(offsprings.at(0) != parents.at(0));
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "first");
        }
    }

    configuration.getBreederConfiguration().threads = 2;
    auto *breeder = new Breeder(configuration, *bo);
    SECTION("Breeder") {
        dynamic_cast<SimpleIndividual *>(pop->getIndividuals().at(0))->setLabel("first");
        SECTION("Variating a population...") {
            auto *offsprings = breeder->breedPopulation(*pop);
            REQUIRE(offsprings->at(0) != pop->getIndividuals().at(0));
            REQUIRE(offsprings->at(0)->toString() == pop->getIndividuals().at(0)->toString());
            REQUIRE(offsprings->at(1) != pop->getIndividuals().at(1));
            REQUIRE(offsprings->at(1)->toString() != pop->getIndividuals().at(1)->toString());
            REQUIRE(offsprings->at(2) != pop->getIndividuals().at(2));
            REQUIRE(offsprings->at(2)->toString() != pop->getIndividuals().at(2)->toString());
        }

    }

    delete breeder;
    delete thread;
    delete pop;


    SECTION("Statistics") {
        problem->getConfiguration().popsize = 2;
        configuration.getEvolutionarySystemConfiguration().epochs = 3;
        configuration.getEvolutionarySystemConfiguration().episodes = 2;
        configuration.getEvolutionarySystemConfiguration().generations = 1;
        auto *p = new Population(configuration);
        auto *init = new Initializer(configuration, *builder, epoch);
        init->initializePopulation(*p);
        auto *statistics = new Statistics(configuration);
        for (unsigned int k = 0; k < 3; k++) {
            p->getIndividuals().at(0)->getRelevance().setFraction(k / 2.0f);
            p->getIndividuals().at(0)->getRelevance().setCost(10);
            p->getIndividuals().at(0)->getRelevance().setFitness(0);
            p->getIndividuals().at(1)->getRelevance().setFraction(k / 2.0f);
            p->getIndividuals().at(1)->getRelevance().setCost(5);
            p->getIndividuals().at(1)->getRelevance().setFitness(2.5);
            statistics->record(*p, k, 0);
            p->getIndividuals().at(0)->getRelevance().setCost(0);
            p->getIndividuals().at(0)->getRelevance().setFitness(7.5);
            p->getIndividuals().at(1)->getRelevance().setCost(2.5);
            p->getIndividuals().at(1)->getRelevance().setFitness(2.5);
            statistics->record(*p, k, 0);
        }

        SECTION("Checking best cost recording...") {
            REQUIRE(statistics->bestCost(0).at(0) == 2.5f);
            REQUIRE(statistics->bestCost(1).at(0) == 2.5f);
            REQUIRE(statistics->bestCost(2).at(0) == 2.5f);
        }

        SECTION("Checking average cost recording...") {
            REQUIRE(statistics->averageCost(0).at(0) == 4.375f);
            REQUIRE(statistics->averageCost(1).at(0) == 4.375f);
            REQUIRE(statistics->averageCost(2).at(0) == 4.375f);
        }

        SECTION("Checking worst cost recording...") {
            REQUIRE(statistics->worstCost(0).at(0) == 6.25f);
            REQUIRE(statistics->worstCost(1).at(0) == 6.25f);
            REQUIRE(statistics->worstCost(2).at(0) == 6.25f);
        }

        SECTION("Checking best fitness recording...") {
            REQUIRE(statistics->bestFitness(0).at(0) == 1.25f);
            REQUIRE(statistics->bestFitness(1).at(0) == 1.25f);
            REQUIRE(statistics->bestFitness(2).at(0) == 1.25f);
        }

        SECTION("Checking average fitness recording...") {
            REQUIRE(statistics->averageFitness(0).at(0) == 3.125f);
            REQUIRE(statistics->averageFitness(1).at(0) == 3.125f);
            REQUIRE(statistics->averageFitness(2).at(0) == 3.125f);
        }

        SECTION("Checking worst fitness recording...") {
            REQUIRE(statistics->worstFitness(0).at(0) == 5.0f);
            REQUIRE(statistics->worstFitness(1).at(0) == 5.0f);
            REQUIRE(statistics->worstFitness(2).at(0) == 5.0f);
        }

        SECTION("Checking best relevance recording") {
            REQUIRE(statistics->bestRelevance(0).at(0) == 1.25f);
            REQUIRE(statistics->bestRelevance(1).at(0) == 3.125f);
            REQUIRE(statistics->bestRelevance(2).at(0) == 2.5f);
        }

        SECTION("Checking average relevance recording... ") {
            REQUIRE(statistics->averageRelevance(0).at(0) == 3.125f);
            REQUIRE(statistics->averageRelevance(1).at(0) == 3.75f);
            REQUIRE(statistics->averageRelevance(2).at(0) == 4.375f);
        }

        SECTION("Checking worst relevance recording...") {
            REQUIRE(statistics->worstRelevance(0).at(0) == 5.0f);
            REQUIRE(statistics->worstRelevance(1).at(0) == 4.375f);
            REQUIRE(statistics->worstRelevance(2).at(0) == 6.25f);
        }

        SECTION("Checking most relevant cost recording...") {
            REQUIRE(statistics->mostRelevantCost(0).at(0) == 6.25f);
            REQUIRE(statistics->mostRelevantCost(1).at(0) == 3.75f);
            REQUIRE(statistics->mostRelevantCost(2).at(0) == 2.5f);
        }

        SECTION("Checking least relevant cost recording...") {
            REQUIRE(statistics->leastRelevantCost(0).at(0) == 2.5f);
            REQUIRE(statistics->leastRelevantCost(1).at(0) == 5.0f);
            REQUIRE(statistics->leastRelevantCost(2).at(0) == 6.25f);
        }

        SECTION("Checking most relevant fitness recording...") {
            REQUIRE(statistics->mostRelevantFitness(0).at(0) == 1.25f);
            REQUIRE(statistics->mostRelevantFitness(1).at(0) == 2.5f);
            REQUIRE(statistics->mostRelevantFitness(2).at(0) == 5.0f);
        }

        SECTION("Checking least relevant fitness recording...") {
            REQUIRE(statistics->leastRelevantFitness(0).at(0) == 5.0f);
            REQUIRE(statistics->leastRelevantFitness(1).at(0) == 3.75f);
            REQUIRE(statistics->leastRelevantFitness(2).at(0) == 1.25f);
        }

        delete statistics;
        delete init;
        delete p;
    }

    problem->getConfiguration().popsize = 10;
    configuration.getEvolutionarySystemConfiguration().epochs = 1;
    configuration.getEvolutionarySystemConfiguration().episodes = 1;
    configuration.getEvolutionarySystemConfiguration().generations = 10;
    SECTION("EvolutionarySystem") {
        auto *system = new EvolutionarySystem(configuration, *builder, *eval, *network, *bo);

        SECTION("Running a dummy...") {
            system->run();
            REQUIRE(true);
        }

        delete system;
    }

    delete bo;
    delete network;
    delete builder;
    delete session;
    delete problem;
    delete eval;
}