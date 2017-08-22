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
    unsigned int generations = 200; // Maximum number of generations to evolve.

    unsigned int evalthreads  = 1;
    unsigned int breedthreads = 1;

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

};


#endif //NDEC_MODULE_H
