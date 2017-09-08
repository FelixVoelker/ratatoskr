#ifndef NDEC_PROBLEMWRAPPER_H
#define NDEC_PROBLEMWRAPPER_H


#include <boost/python.hpp>
#include "../../../../cc/ec/ndga/NDGAProblem.h"

using namespace boost::python;

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   24.8.2017
 */
class ProblemWrapper : public NDGAProblem, public wrapper<NDGAProblem> {

public:
    explicit ProblemWrapper(unsigned int popsize, unsigned int genes);

    void evaluate(Individual &individual) const override;

};


#endif //NDEC_PROBLEMWRAPPER_H
