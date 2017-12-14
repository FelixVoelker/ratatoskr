#ifndef RATATOSKR_INDIVIDUALWRAPPER_H
#define RATATOSKR_INDIVIDUALWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Individual.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Individual.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   14.12.2017
 */
class IndividualWrapper : public Individual, public wrapper<Individual> {

public:
    explicit IndividualWrapper(boost::shared_ptr<Session> session);

    std::string toString() override;

    Individual * clone() const override;

};


#endif //RATATOSKR_INDIVIDUALWRAPPER_H
