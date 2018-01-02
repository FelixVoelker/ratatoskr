#ifndef RATATOSKR_SESSION_H
#define RATATOSKR_SESSION_H


#include "evaluation/Problem.h"

//class EvolutionaryNetwork;
class Builder;
class Fitness;
class Cost;
class FeatureMap;
class Individual;
class BreedingOperator;

/**
 * TODO: Comments
 * Represents the blueprint class for all Session objects of NDEC. A session is a run of a particular neuro-dynamic
 * evolutionary computation method on a given problem. It configures all the components that are necessary to run
 * this method.
 *
 * @author  Felix Voelker
 * @version 0.2
 * @since   1.9.2017
 */
class Session {

public:
    explicit Session(Problem &problem);
    virtual ~Session();

    Problem & getProblem() const;

//    EvolutionaryNetwork * getNetwork() const;
    Builder *             getBuilder() const;
    Fitness *             getFitness() const;
    Cost  *               getCost() const;
    FeatureMap *          getFeaturemap() const;
    Individual *          getIndividual() const;
    BreedingOperator *    getVariationTree() const;

//    virtual void setNetwork(EvolutionaryNetwork &network_prototype) = 0;
    virtual void setBuilder(Builder &builder_prototype) = 0;
    virtual void setFitness(Fitness &fitness_prototype) = 0;
    virtual void setCost(Cost &cost_prototype) = 0;
    virtual void setFeaturemap(FeatureMap &featuremap_prototype) = 0;
    virtual void setIndividual(Individual &individual_prototype) = 0;
//    virtual void setPipeline(BreedingOperator &pipeline_prototype) = 0;


    unsigned int getEpochs() const;
    unsigned int getEpisodes() const;
    unsigned int getGenerations() const;
    bool isComplete() const;
    unsigned int getInitthreads() const;
    unsigned int getEvalthreads() const;
    unsigned int getVarythreads() const;
    float getLearningRate() const;
    float getDiscountFactor() const;

    void setEpochs(unsigned int epochs);
    void setEpisodes(unsigned int episodes);
    void setGenerations(unsigned int generations);
    void setComplete(bool complete);
    void setInitthreads(unsigned int initthreads);
    void setEvalthreads(unsigned int evalthreads);
    void setVarythreads(unsigned int varythreads);
    void setLearningRate(float learning_rate);
    void setDiscountFactor(float discount_factor);

protected:
    unsigned int epochs = 1; // Number of getEpochs to run.
    unsigned int episodes = 1; // Number of evolutions in each epoch.
    unsigned int generations = 200; // Maximum number of getGenerations to evolve.

    bool complete = false; // Determines whether an evolution progresses until the maximum generation.

    unsigned int initthreads = 1; // Number of used threads during initialization phase.
    unsigned int evalthreads  = 1; // Number of used threads during evaluation phase.
    unsigned int varythreads = 1; // Number of used threads during variation phase.

    float learning_rate = 0.1;
    float discount_factor = 0.1;

    Problem &problem;

    /**
     * Necessary prototypes.
     */
//    EvolutionaryNetwork *network;
    Builder             *builder;
    Fitness             *fitness;
    Cost                *cost;
    FeatureMap          *featuremap;
    Individual          *individual;
    BreedingOperator    *variation_tree;

};


#endif //RATATOSKR_MODULE_H
