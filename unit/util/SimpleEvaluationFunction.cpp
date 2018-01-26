#include "SimpleEvaluationFunction.h"

SimpleEvaluationFunction::SimpleEvaluationFunction() : EvaluationFunction() {}

EvaluationFunction * SimpleEvaluationFunction::clone() const {
    return new SimpleEvaluationFunction(*this);
}

void SimpleEvaluationFunction::operator()(Individual &individual, Thread &thread) {
    individual.getRelevance().setFitness(1);
}