#ifndef RATATOSKR_EVALUATIONFUNCTIONWRAPPER_H
#define RATATOSKR_EVALUATIONFUNCTIONWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/evaluation/EvaluationFunction.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of EvaluationFunction.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   26.1.2018
 */
class EvaluationFunctionWrapper : public EvaluationFunction, public wrapper<EvaluationFunction> {

public:
    explicit EvaluationFunctionWrapper();

    EvaluationFunction * clone() const override;

    void operator()(Individual &individual, Thread &thread) override;

};


#endif //RATATOSKR_EVALUATIONFUNCTIONWRAPPER_H
