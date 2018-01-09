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

/**
 * Unit tests for the core functionality of an evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   8.1.2018
 */
TEST_CASE("Core", "[core]") {
    std::function<void(Individual &, Thread &)> eval = [](Individual &individual, Thread &thread) {
        individual.getFitness().setFitness(1);
    };
    auto *problem = new Problem(eval, 1);
    auto *session = new Session(*problem);
    auto &configuration = session->getConfiguration();

    SECTION("Cost") {
        auto *c1 = new Cost(configuration);
        c1->setCost(2);
        auto *c2 = new Cost(configuration);
        c2->setCost(5);
        auto *c3 = new Cost(configuration);
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
        auto *f1 = new Fitness(configuration);
        f1->setFitness(2);
        auto *f2 = new Fitness(configuration);
        f2->setFitness(5);
        auto *f3 = new Fitness(configuration);
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

    auto *cost = new Cost(configuration);
    auto *featuremap = new SimpleFeatureMap(configuration);
    auto *fitness = new Fitness(configuration);
    auto *individual = new SimpleIndividual(configuration, cost, featuremap, fitness);
    SECTION("Individual") {
        individual->getFitness().setFitness(2.5);
        individual->getCost().setCost(5);

        SECTION("Checking computation of relevance...") {
            REQUIRE(individual->relevance(-1) == static_cast<float>(1 / (1 + 2.5)));
            REQUIRE(individual->relevance(0.5) == static_cast<float>(1 / (1 + 3.75)));
            REQUIRE(individual->relevance(2) == static_cast<float>(1 / (1 + 5.0)));
        }

        SECTION("Checking cloning...") {
            auto *copy = individual->clone();
            REQUIRE(individual != copy);
            REQUIRE(individual->getCost().getCost() == copy->getCost().getCost());
            REQUIRE(individual->getFitness().getFitness() == copy->getFitness().getFitness());
            delete copy;
        }
    }

    unsigned int epoch = 0;
    auto *thread = new Thread(0, 3, epoch);
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
                counts.at(thread->random.sampleIntFromDiscreteDistribution(weights)) += 1;
            }

            REQUIRE(counts.at(0) > counts.at(1));
            REQUIRE(counts.at(1) > counts.at(2));
        }
    }

    auto *builder = new SimpleBuilder(configuration, individual);
    SECTION("Builder") {
        auto *ind = builder->build(*thread);

        SECTION("Checking initialization...") {
            REQUIRE(ind->toString() == "passed");
        }

        delete ind;
    }

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
        pop->getIndividuals().at(0)->getCost().setCost(0);
        pop->getIndividuals().at(0)->getFitness().setFitness(0);
        pop->getIndividuals().at(1) = builder->build(*thread);
        pop->getIndividuals().at(1)->getCost().setCost(3);
        pop->getIndividuals().at(1)->getFitness().setFitness(5);
        pop->getIndividuals().at(2) = builder->build(*thread);
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
    }

    configuration.getInitializerConfiguration().threads = 2;
    auto *initializer = new Initializer(configuration, builder, epoch);
    initializer->initializePopulation(*pop);
    SECTION("Initializer") {
        SECTION("Initializating a population...") {
            REQUIRE(pop->getIndividuals().at(0)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(1)->toString() == "passed");
            REQUIRE(pop->getIndividuals().at(2)->toString() == "passed");
        }
    }

    configuration.getEvaluatorConfiguration().threads = 2;
    auto *network = new SimpleEvolutionaryNetwork(configuration);
    auto *evaluator = new Evaluator(configuration, eval, network, epoch);
    SECTION("Evaluator") {
        SECTION("Evaluating a population...") {
            evaluator->evaluatePopulation(*pop);
            evaluator->evaluatePopulation(*pop);
            REQUIRE(pop->getIndividuals().at(0)->getFitness().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(1)->getFitness().getFitness() == 1);
            REQUIRE(pop->getIndividuals().at(2)->getFitness().getFitness() == 1);
        }
    }


    SECTION("VariationSource") {
        auto *vs = new SimpleVariationSource(configuration);
        vs->setup(*new std::vector<VariationSource *>(0));

        SECTION("Checking workflow...") {
            std::vector<Individual *> parents = pop->getIndividuals();
            std::vector<Individual *> offsprings = vs->vary(parents, *thread);
            REQUIRE(dynamic_cast<SimpleIndividual *>(offsprings.at(0))->toString() == "bred");
        }

        delete vs;
    }

    auto *so = new SimpleSelectionOperator(configuration);
    so->setup(*new std::vector<VariationSource *>(0));
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
    bo->setup(*new std::vector<VariationSource *> = { so });
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
    auto *breeder = new Breeder(configuration, bo, epoch);
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

    delete thread;
    delete initializer;
    delete evaluator;
    delete breeder;

    configuration.getEvolutionarySystemConfiguration().epochs = 1;
    configuration.getEvolutionarySystemConfiguration().episodes = 3;
    configuration.getEvolutionarySystemConfiguration().generations = 1;
    SECTION("Statistics") {
        auto *statistics = new Statistics(configuration);
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
    }

    SECTION("EvolutionarySystem") {
        auto *system = new EvolutionarySystem(configuration, builder, eval, network, bo);

        SECTION("Running a dummy...") {
            system->run();
            REQUIRE(true);
        }

        delete system;
    }

    delete bo;
    delete network;
    delete builder;
    delete pop;
    delete session;
    delete problem;
}