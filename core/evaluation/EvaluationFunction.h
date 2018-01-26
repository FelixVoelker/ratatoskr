#ifndef RATATOSKR_EVALUATIONFUNCTION_H
#define RATATOSKR_EVALUATIONFUNCTION_H


#include "../representation/Individual.h"
#include "../util/Thread.h"

/**
 * The abstract base class for all evaluation functions that are used as part of an optimization problem's
 * specification. These functions are provided to the evolutionary system as functors and therefore need to override
 * the call operator.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   26.1.2018
 */
class EvaluationFunction : public Clonable {

public:
    explicit EvaluationFunction();

    virtual EvaluationFunction * clone() const = 0;

    /**
     * Assigns a fitness value to an individual according to the specification of the problem.
     * @param individual The individual to be evaluated.
     * @param thread     The evaluating thread.
     */
    virtual void operator()(Individual &individual, Thread &thread) = 0;

protected:
    EvaluationFunction(const EvaluationFunction &obj) = default;

};


#endif //RATATOSKR_EVALUATIONFUNCTION_H
