#ifndef RATATOSKR_UNIT_SIMPLEEVALUATIONFUNCTION_H
#define RATATOSKR_UNIT_SIMPLEEVALUATIONFUNCTION_H


#include "../../core/evaluation/EvaluationFunction.h"

/**
 * A simple instance of EvaluationFunction to test core functionality.
 *
 * @author Felix Voelker
 * @version 0.1.1
 * @since   26.1.2018
 */
class SimpleEvaluationFunction : public EvaluationFunction {

public:
    explicit SimpleEvaluationFunction();

    EvaluationFunction * clone() const override;

    void operator()(Individual &individual, Thread &thread) override;

protected:
    SimpleEvaluationFunction(const SimpleEvaluationFunction &obj) = default;

};


#endif //RATATOSKR_UNIT_SIMPLEEVALUATIONFUNCTION_H
