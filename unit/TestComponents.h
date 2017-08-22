#ifndef NDEC_TESTCOMPONENTS_H
#define NDEC_TESTCOMPONENTS_H


#include "../core/evaluation/Problem.h"
#include "../core/variation/BreedingOperator.h"

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   6.8.2017
 */
class TestProblem : public Problem {

public:
    TestProblem();

    void evaluate(Individual &individual) override;

};

class TestSession : public Session {

public:
    explicit TestSession(Problem &problem);

    void builder(Builder &builder_prototype) override;
    void fitness(Fitness &fitness_prototype) override;
    void featuremap(FeatureMap &featuremap_prototype) override;
    void individual(Individual &individual_prototype) override;
    void pipeline(BreedingOperator &pipeline_prototype) override;

};

class TestBuilder : public Builder {

protected:
    void initialize(Individual &ind) override;

public:
    explicit TestBuilder(Session &session);

};

class TestIndividual : public Individual {

public:
    explicit TestIndividual(Session &session);
    string toString() override;

    TestIndividual * clone() override;

};

class TestFeatureMap : public FeatureMap {

public:
    explicit TestFeatureMap(Session &session);

    TestFeatureMap * clone() override;

};

class TestSource : public VariationSource {

    protected:
        unsigned long expectedSources() override;

    protected:
        vector<Individual *> perform(Population &pop, vector<Individual *> parents, Randomizer &random) override;

    public:
        explicit TestSource(Session &session);

};

class TestBreedingOperator : public BreedingOperator {

    protected:
        unsigned long expectedSources();

    public:
        explicit TestBreedingOperator(Session &session);

        vector<Individual *> breed(vector<Individual *> parents, Randomizer &random) override;

};

#endif //NDEC_TESTCOMPONENTS_H
