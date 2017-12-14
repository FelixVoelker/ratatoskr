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
class SimpleSession : public Session {

public:
    explicit SimpleSession(Problem &problem);

//    void setBuilder(Builder &builder_prototype) override;
    void setCost(Cost &cost_prototype) override;
    void setFeaturemap(FeatureMap &featuremap_prototype) override;
    void setFitness(Fitness &fitness_prototype) override;
    void setIndividual(Individual &individual_prototype) override;
//    void setPipeline(BreedingOperator &pipeline_prototype) override;

};


#endif //RATATOSKR_CORE_TESTSESSION_H
