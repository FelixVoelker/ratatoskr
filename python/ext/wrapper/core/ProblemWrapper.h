#ifndef NDEC_PROBLEMWRAPPER_H
#define NDEC_PROBLEMWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/evaluation/Problem.h"
#include "../../../../core/representation/Individual.h"

using namespace boost::python;


/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   23.8.2017
 */
class ProblemWrapper : public Problem, public wrapper<Problem> {

public:
    explicit ProblemWrapper(unsigned int popsize);

    void evaluate(Individual &individual) override;

};


#endif //NDEC_PROBLEMWRAPPER_H
