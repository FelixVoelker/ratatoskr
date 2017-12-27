#ifndef RATATOSKR_SESSIONWRAPPER_H
#define RATATOSKR_SESSIONWRAPPER_H


#include <boost/python.hpp>
//#include "../../../../core/evaluation/EvolutionaryNetwork.h"
#include "../../../../core/Session.h"
#include "../../../../core/initialization/Builder.h"
#include "../../../../core/representation/Cost.h"
#include "../../../../core/representation/FeatureMap.h"
#include "../../../../core/representation/Fitness.h"
#include "../../../../core/representation/Individual.h"
//#include "../../../../core/variation/BreedingOperator.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class SessionWrapper : public Session, public wrapper<Session> {

public:
    explicit SessionWrapper(boost::shared_ptr<Problem> problem);

//    void setNetwork(EvolutionaryNetwork &network_prototype) override;
    void setBuilder(Builder &builder_prototype) override;
    void setCost(Cost &relevance_prototype) override;
    void setFeaturemap(FeatureMap &featuremap_prototype) override;
    void setFitness(Fitness &fitness_prototype) override;
    void setIndividual(Individual &individual_prototype) override;
//    void setPipeline(BreedingOperator &pipeline_prototype) override;

    void pyBuilder(boost::shared_ptr<Builder> builder_prototype);
    void pyCost(boost::shared_ptr<Cost> cost_prototype);
    void pyFeaturemap(boost::shared_ptr<FeatureMap> featuremap_prototype);
    void pyFitness(boost::shared_ptr<Fitness> fitness_prototype);
    void pyIndividual(boost::shared_ptr<Individual> individual_prototype);

};


#endif //RATATOSKR_SESSIONWRAPPER_H
