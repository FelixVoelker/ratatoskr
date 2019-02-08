#include "EvaluationFunctionWrapper.h"

EvaluationFunctionWrapper::EvaluationFunctionWrapper() : EvaluationFunction() {}

EvaluationFunction* EvaluationFunctionWrapper::clone() const {
    return this->get_override("clone")();
}

void EvaluationFunctionWrapper::operator()(Individual &individual, Thread &thread) {
    this->get_override("operator()")(individual, thread);
}