#ifndef RATATOSKR_INDIVIDUALWRAPPER_H
#define RATATOSKR_INDIVIDUALWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/representation/Individual.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Individual.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class IndividualWrapper : public Individual, public wrapper<Individual> {

public:
    explicit IndividualWrapper(const core::Configuration &configuration, FeatureMap *featuremap, Relevance *relevance);

    std::string toString() override;

    Individual * clone() const override;

};


#endif //RATATOSKR_INDIVIDUALWRAPPER_H
