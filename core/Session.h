#ifndef NDEC_SESSION_H
#define NDEC_SESSION_H


#include <Python.h>
#include "evaluation/Problem.h"

class Builder;

class Fitness;
class FeatureMap;

class BreedingOperator;

/**
 * Represents the blueprint class for all Session objects of NDEC. A session is a run of a particular neuro-dynamic
 * evolutionary computation method on a given problem. It configures all the components that are necessary to run
 * this method.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class Session {

protected:
    unsigned int _generations = 200; // Maximum number of generations to evolve.

    unsigned int _evalthreads  = 1; // Number of used threads during evaluation phase.
    unsigned int _varythreads = 1; // Number of used threads during variation phase.

    Problem &_problem;

    /**
     * Necessary prototypes.
     */
    Builder          *_builder;
    Fitness          *_fitness;
    FeatureMap       *_featuremap;
    Individual       *_individual;
    BreedingOperator *_pipeline;

public:
    explicit Session(Problem &problem);
    ~Session();

    Problem & problem();

    Builder ** builder();
    Fitness ** fitness();
    FeatureMap ** featuremap();
    Individual ** individual();
    BreedingOperator ** pipeline();

    virtual void builder(Builder &builder_prototype) = 0;
    virtual void fitness(Fitness &fitness_prototype) = 0;
    virtual void featuremap(FeatureMap &featuremap_prototype) = 0;
    virtual void individual(Individual &individual_prototype) = 0;
    virtual void pipeline(BreedingOperator &pipeline_prototype) = 0;

    unsigned int generations();
    unsigned int evalthreads();
    unsigned int varythreads();

    void generations(unsigned int generations);
    void evalthreads(unsigned int evalthreads);
    void varythreads(unsigned int varythreads);

};


#endif //NDEC_MODULE_H
