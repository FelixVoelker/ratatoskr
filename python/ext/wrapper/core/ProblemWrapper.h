#ifndef RATATOSKR_PROBLEMWRAPPER_H
#define RATATOSKR_PROBLEMWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/representation/Individual.h"
#include "../../../../core/evaluation/Problem.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of Problem.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class ProblemWrapper : public Problem, public wrapper<Problem> {

public:
    explicit ProblemWrapper(unsigned int popsize);

    void eval(Individual &individual, Thread &thread) const override;

};


#endif // RATATOSKR_PROBLEMWRAPPER_H
