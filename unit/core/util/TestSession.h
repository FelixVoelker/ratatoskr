#ifndef RATATOSKR_CORE_TESTSESSION_H
#define RATATOSKR_CORE_TESTSESSION_H


#include "../../../core/Session.h"

/**
 * An instance of Session to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestSession : public Session {

public:
    explicit TestSession(Problem &problem);

    void builder(Builder &builder_prototype) override;
    void fitness(Fitness &fitness_prototype) override;
    void featuremap(FeatureMap &featuremap_prototype) override;
    void individual(Individual &individual_prototype) override;
    void pipeline(BreedingOperator &pipeline_prototype) override;

};


#endif //RATATOSKR_CORE_TESTSESSION_H
