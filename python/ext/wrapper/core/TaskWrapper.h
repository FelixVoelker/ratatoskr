#ifndef RATATOSKR_TASKWRAPPER_H
#define RATATOSKR_TASKWRAPPER_H


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
class TaskWrapper : public Problem, public wrapper<Problem> {

public:
    explicit TaskWrapper(unsigned int popsize);

    void eval(Individual &individual) const override;

    TaskWrapper * clone() const override;

};


#endif // RATATOSKR_TASKWRAPPER_H
