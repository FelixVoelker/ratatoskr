#ifndef RATATOSKR_EVALUATIONFUNCTION_H
#define RATATOSKR_EVALUATIONFUNCTION_H


#include "../representation/Individual.h"

/**
 * Represents the problem specific evaluation function to be used by the evaluator in order to estimate the fitness
 * of the individuals within an evolutionary system's population.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   10.10.2017
 */
class EvaluationFunction {

    /**
     * Evaluates a given individual according to the problem specific strategy.
     * @param individual Individual to be evaluated.
     */
    virtual void operator()(Individual &individual) const = 0;
};


#endif //RATATOSKR_EVALUATIONFUNCTION_H
