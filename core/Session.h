#ifndef NDEC_SESSION_H
#define NDEC_SESSION_H


#include "evaluation/Problem.h"

class EvolutionaryNetwork;
class Builder;
class Fitness;
class Relevance;
class FeatureMap;
class BreedingOperator;

/**
 * Represents the blueprint class for all Session objects of NDEC. A session is a run of a particular neuro-dynamic
 * evolutionary computation method on a given problem. It configures all the components that are necessary to run
 * this method.
 *
 * @author  Felix Voelker
 * @version 0.2
 * @since   1.9.2017
 */
class Session {

protected:
    unsigned int _epochs = 1; // Number of epochs to run.
    unsigned int _episodes = 1; // Number of evolutions in each epoch.

    unsigned int _generations = 200; // Maximum number of generations to evolve.

    unsigned int _evalthreads  = 1; // Number of used threads during evaluation phase.
    unsigned int _varythreads = 1; // Number of used threads during variation phase.

    float _learning_rate = 0.1;
    float _discount_factor = 0.1;

    Problem &_problem;

    /**
     * Necessary prototypes.
     */
    EvolutionaryNetwork *_network;
    Builder             *_builder;
    Fitness             *_fitness;
    Relevance           *_relevance;
    FeatureMap          *_featuremap;
    Individual          *_individual;
    BreedingOperator    *_pipeline;

public:
    explicit Session(Problem &problem);
    ~Session();

    Problem & problem();

    EvolutionaryNetwork * network();
    Builder * builder();
    Fitness * fitness();
    Relevance  * relevance();
    FeatureMap * featuremap();
    Individual * individual();
    BreedingOperator * pipeline();

    virtual void network(EvolutionaryNetwork &network_prototype) = 0;
    virtual void builder(Builder &builder_prototype) = 0;
    virtual void fitness(Fitness &fitness_prototype) = 0;
    virtual void relevance(Relevance &relevance_prototype) = 0;
    virtual void featuremap(FeatureMap &featuremap_prototype) = 0;
    virtual void individual(Individual &individual_prototype) = 0;
    virtual void pipeline(BreedingOperator &pipeline_prototype) = 0;


    unsigned int epochs();
    unsigned int episodes();
    unsigned int generations();
    unsigned int evalthreads();
    unsigned int varythreads();
    float learning_rate();
    float discount_factor();

    void epochs(unsigned int epochs);
    void episodes(unsigned int episodes);
    void generations(unsigned int generations);
    void evalthreads(unsigned int evalthreads);
    void varythreads(unsigned int varythreads);
    void learning_rate(float learning_rate);
    void discount_factor(float discount_factor);

};


#endif //NDEC_MODULE_H
