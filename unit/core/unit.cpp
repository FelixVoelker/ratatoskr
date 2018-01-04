#define CATCH_CONFIG_MAIN


#include <catch.hpp>
#include "util/SimpleBuilder.h"
#include "util/SimpleProblem.h"
#include "util/SimpleSession.h"
#include "../../core/representation/Population.h"
#include "util/SimpleVariationSource.h"
#include "util/SimpleIndividual.h"
#include "util/SimpleSelectionOperator.h"
#include "util/SimpleBreedingOperator.h"
#include "../../core/initialization/Initializer.h"
#include "../../core/evaluation/Evaluator.h"
#include "../../core/variation/Breeder.h"
#include "../../core/statistics/Statistics.h"
#include "../../core/EvolutionarySystem.h"

/**
 * Unit tests for the core functionality of an evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   28.12.2017
 */
TEST_CASE("Core", "[core]") {
    auto problem = new SimpleProblem(1);
    auto session = new SimpleSession(*problem);

    SECTION("Cost") {
        auto *c1 = new Cost(*session);
        c1->setCost(2);
        auto *c2 = new Cost(*session);
        c2->setCost(5);
        auto *c3 = new Cost(*session);
        c3->setCost(0);

        SECTION("Checking computation of error...") {
            REQUIRE(c1->error(1, 0.5, 0) == -1.5);
            REQUIRE(c2->error(1, 0.5, 2) == -2.5);
            REQUIRE(c3->error(1, 0.5, 0) == 0.5);
        }

        SECTION("Checking comparison of costs...") {
            REQUIRE(*c1 > *c2);
            REQUIRE(*c2 < *c3);
            REQUIRE(*c1 < *c3);
        }

        SECTION("Checking cloning...") {
            auto *cc = c1->clone();
            REQUIRE(cc != c1);
            REQUIRE(cc->getCost() == c1->getCost());
            delete cc;
        }

        delete c1;
        delete c2;
        delete c3;
    }

    SECTION("Fitness") {
        auto *f1 = new Fitness(*session);
        f1->setFitness(2);
        auto *f2 = new Fitness(*session);
        f2->setFitness(5);
        auto *f3 = new Fitness(*session);
        f3->setFitness(0);

        SECTION("Checking optimality of fitnesses...") {
            REQUIRE(!f1->isIdeal());
            REQUIRE(!f2->isIdeal());
            REQUIRE(f3->isIdeal());
        }

        SECTION("Checking comparison of fitnesses...") {
            REQUIRE(*f1 > *f2);
            REQUIRE(*f2 < *f3);
            REQUIRE(*f1 < *f3);
        }

        SECTION("Checking cloning...") {
            auto *fc = f1->clone();
            REQUIRE(fc != f1);
            REQUIRE(f1->getFitness() == fc->getFitness());
            delete fc;
        }

        delete f1;
        delete f2;
        delete f3;
    }

    SECTION("Individual") {
        auto *i1 = session->getIndividual();
        i1->getFitness().setFitness(2.5);
        i1->getCost().setCost(5);

        SECTION("Checking computation of relevance...") {
            REQUIRE(i1->relevance(-1) == static_cast<float>(1 / (1 + 2.5)));
            REQUIRE(i1->relevance(0.5) == static_cast<float>(1 / (1 + 3.75)));
            REQUIRE(i1->relevance(2) == static_cast<float>(1 / (1 + 5.0)));
        }

        SECTION("Checking cloning...") {
            auto *ic = i1->clone();
            REQUIRE(i1 != ic);
            REQUIRE(i1->getCost().getCost() == ic->getCost().getCost());
            REQUIRE(i1->getFitness().getFitness() == ic->getFitness().getFitness());
            delete ic;
        }
    }

    auto *builder = session->getBuilder();
    SECTION("Builder") {
        auto *ind = builder->build();

        SECTION("Checking initialization...") {
            REQUIRE(ind->toString() == "passed");
        }

        delete ind;
    }

    SECTION("Population") {
        session->getProblem().setPopsize(3);
        auto *pop = new Population(*session);
        pop->getIndividuals().at(0) = builder->build();
        pop->getIndividuals().at(1) = builder->build();
        pop->getIndividuals().at(2) = builder->build();

        SECTION("Checking extermination...") {
            pop->exterminate();
            for (auto ind : pop->getIndividuals()) {
                REQUIRE(ind == nullptr);
            }
        }

        pop->getIndividuals().at(0) = builder->build();
        pop->getIndividuals().at(0)->getCost().setCost(0);
        pop->getIndividuals().at(0)->getFitness().setFitness(0);
        pop->getIndividuals().at(1) = builder->build();
        pop->getIndividuals().at(1)->getCost().setCost(3);
        pop->getIndividuals().at(1)->getFitness().setFitness(5);
        pop->getIndividuals().at(2) = builder->build();
        pop->getIndividuals().at(2)->getCost().setCost(7.5);
        pop->getIndividuals().at(2)->getFitness().setFitness(2.5);

        SECTION("Finding the best individual...") {
            REQUIRE(pop->bestIndividual() == pop->getIndividuals().at(0));
        }

        SECTION("Finding the worst individual...") {
            REQUIRE(pop->worstIndividual() == pop->getIndividuals().at(1));
        }

        SECTION("Computing the average individual...") {
            auto *average = pop->averageIndividual();
            REQUIRE(average->getCost().getCost() == 3.5);
            REQUIRE(average->getFitness().getFitness() == 2.5);
            delete average;
        }

        delete pop;
    }

    unsigned int epoch = 0;
    SECTION("Thread") {
        auto t = new Thread(0, 3, epoch);

        SECTION("Checking sampling from uniform distribution...") {
            std::vector<unsigned int> counts = std::vector<unsigned int>(3);
            counts.at(0) = 0;
            counts.at(1) = 0;
            counts.at(2) = 0;

            for (unsigned int k = 1; k <= 1000; k++) {
                counts.at(t->random.sampleIntFromUniformDistribution(3)) += 1;
            }

            unsigned int tolerance = 100;
            REQUIRE(counts.at(0) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(0) + tolerance);
            REQUIRE(counts.at(2) - tolerance <= counts.at(1));
            REQUIRE(counts.at(1) <= counts.at(2) + tolerance);
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
                counts.at(t->random.sampleIntFromDiscreteDistribution(weights)) += 1;
            }

            REQUIRE(counts.at(0) > counts.at(1));
            REQUIRE(counts.at(1) > counts.at(2));
        }

        delete t;
    }

    session->getProblem().setPopsize(3);
    SECTION("VariationSource") {
        auto *vs = new SimpleVariationSource(*session);
        vs->setup(*new std::vector<VariationSource *>(0));

        auto *t = new Thread(0, 3, epoch);
        SECTION("Checking workflow...") {
            auto *pop = new Population(*session);
            pop->getIndividuals().at(0) = builder->build();
            pop->getIndividuals().at(1) = builder->build();
            pop->getIndividuals().at(2) = builder->build();
            std::vector<Individual *> parents = pop->getIndividuals();
            std::vector<Individual *> offsprings = vs->vary(parents, *t);
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "bred");
            delete pop;
        }

        delete vs;
        delete t;
    }

    SECTION("SelectionOperator") {
        auto *so = new SimpleSelectionOperator(*session);
        so->setup(*new std::vector<VariationSource *>(0));

        auto *t = new Thread(0, 3, epoch);
        SECTION("Checking selection...") {
            auto *pop = new Population(*session);
            pop->getIndividuals().at(0) = builder->build();
            pop->getIndividuals().at(1) = builder->build();
            pop->getIndividuals().at(2) = builder->build();
            std::vector<Individual *> parents = pop->getIndividuals();
            dynamic_cast<SimpleIndividual *>(parents.at(0))->setLabel("first");
            dynamic_cast<SimpleIndividual *>(parents.at(1))->setLabel("second");
            dynamic_cast<SimpleIndividual *>(parents.at(2))->setLabel("third");
            std::vector<Individual *> offsprings = so->vary(parents, *t);
            REQUIRE(offsprings.size() == 1);
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "first");
            delete pop;
        }

        delete so;
        delete t;
    }

    SECTION("BreedingOperator") {
        auto *so = new SimpleSelectionOperator(*session);
        so->setup(*new std::vector<VariationSource *>(0));
        auto *bo = new SimpleBreedingOperator(*session);
        bo->setup(*new std::vector<VariationSource *> = { so });
        auto *t = new Thread(0, 3, epoch);

        SECTION("Checking breeding...") {
            auto *pop = new Population(*session);
            pop->getIndividuals().at(0) = builder->build();
            pop->getIndividuals().at(1) = builder->build();
            pop->getIndividuals().at(2) = builder->build();
            std::vector<Individual *> parents = pop->getIndividuals();
            dynamic_cast<SimpleIndividual *>(parents.at(0))->setLabel("first");
            dynamic_cast<SimpleIndividual *>(parents.at(1))->setLabel("second");
            dynamic_cast<SimpleIndividual *>(parents.at(2))->setLabel("third");
            std::vector<Individual *> offsprings = bo->vary(parents, *t);
            REQUIRE(offsprings.at(0) != parents.at(0));
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "first");
            delete pop;
        }

        delete bo;
        delete t;
    }

    SECTION("Problem") {
        auto *individual = session->getIndividual()->clone();
        auto *t = new Thread(0, 1, epoch);

        SECTION("Evaluating an individual...") {
            problem->eval(*individual, *t);
            REQUIRE(individual->getFitness().getFitness() == 1);
        }

        delete t;
    }

    SECTION("Statistics") {
        session->getProblem().setPopsize(3);
        session->setEpochs(1);
        session->setEpisodes(3);
        session->setGenerations(1);

        auto *pop = new Population(*session);
        pop->getIndividuals().at(0) = session->getBuilder()->build();
        pop->getIndividuals().at(1) = session->getBuilder()->build();
        pop->getIndividuals().at(2) = session->getBuilder()->build();

        auto *statistics = new Statistics(*session);
        pop->getIndividuals().at(0)->getFitness().setFitness(0);
        pop->getIndividuals().at(1)->getFitness().setFitness(1.5);
        pop->getIndividuals().at(2)->getFitness().setFitness(8.5);
        statistics->record(*pop, 0, 0);
        pop->getIndividuals().at(0)->getFitness().setFitness(7);
        pop->getIndividuals().at(1)->getFitness().setFitness(5);
        pop->getIndividuals().at(2)->getFitness().setFitness(3);
        statistics->record(*pop, 0, 0);
        pop->getIndividuals().at(0)->getFitness().setFitness(2.5);
        pop->getIndividuals().at(1)->getFitness().setFitness(0);
        pop->getIndividuals().at(2)->getFitness().setFitness(5.5);
        statistics->record(*pop, 0, 0);

        SECTION("Checking best fitness...") {
            REQUIRE(statistics->bestFitnesses(0).at(0) == 1);
        }

        SECTION("Checking average fitness...") {
            REQUIRE(statistics->averageFitnesses(0).at(0) == 10.0f / 9.0f + 15.0f / 9.0f + 8.0f / 9.0f );
        }

        SECTION("Checking worst fitness...") {
            REQUIRE(statistics->worstFitnesses(0).at(0) == 7);
        }

        delete statistics;
        delete pop;
    }

    session->setInitthreads(2);
    session->setEvalthreads(2);
    session->setVarythreads(2);
    auto *pop = new Population(*session);
    auto *initializer = new Initializer(*session, epoch);
    initializer->initializePopulation(*pop);
    SECTION("Initializer") {
        SECTION("Initializating a population...") {
            REQUIRE(pop->getIndividuals().at(0)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(1)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(2)->toString() == "passed");
        }
    }

    SECTION("Evaluator") {
        auto *evaluator = new Evaluator(*session, epoch);

        SECTION("Evaluating a population...") {
            evaluator->evaluatePopulation(*pop);
            REQUIRE(pop->getIndividuals().at(0)->getFitness().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(1)->getFitness().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(2)->getFitness().getFitness() == 1);
        }

        delete evaluator;
    }

    SECTION("Breeder") {
        auto *breeder = new Breeder(*session, epoch);
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

        delete breeder;
    }

    delete initializer;
    delete pop;
    delete session;
    delete problem;

    SECTION("EvolutionarySystem") {
        problem = new SimpleProblem(1);
        session = new SimpleSession(*problem);
        session->setEpochs(2);
        session->setEpisodes(2);
        session->setGenerations(2);
        auto system = new EvolutionarySystem(*session);

        SECTION("Running a dummy...") {
            system->run();
            REQUIRE(true);
        }

        delete system;
        delete session;
        delete problem;
    }

}