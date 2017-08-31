#ifndef NDEC_SESSIONWRAPPER_H
#define NDEC_SESSIONWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/Session.h"
#include "../../../../core/initialization/Builder.h"
#include "../../../../core/representation/Fitness.h"
#include "../../../../core/representation/FeatureMap.h"
#include "../../../../core/representation/Individual.h"
#include "../../../../core/variation/BreedingOperator.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class SessionWrapper : public Session, public wrapper<Session> {

public:
    explicit SessionWrapper(boost::shared_ptr<Problem> problem);

    void builder(Builder &builder_prototype) override;
    void fitness(Fitness &fitness_prototype) override;
    void featuremap(FeatureMap &featuremap_prototype) override;
    void individual(Individual &individual_prototype) override;
    void pipeline(BreedingOperator &pipeline_prototype) override;


};


#endif //NDEC_SESSIONWRAPPER_H
