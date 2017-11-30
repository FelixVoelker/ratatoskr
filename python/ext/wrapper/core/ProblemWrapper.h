#ifndef RATATOSKR_PROBLEMWRAPPER_H
#define RATATOSKR_PROBLEMWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/evaluation/Problem.h"

using namespace boost::python;

/**
 * Represents the Boost.Python wrapper that exposes task objects to the python api.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   15.10.2017
 */
class ProblemWrapper : public Problem, public wrapper<Problem> {

public:
    explicit ProblemWrapper(unsigned int popsize);

//    void eval(Individual &individual) const override;

    ProblemWrapper * clone() const override;

};


#endif // RATATOSKR_PROBLEMWRAPPER_H
