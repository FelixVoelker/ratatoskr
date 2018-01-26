#include "EvaluationFunctions.h"
#include "../common/VectorIndividual.h"

ndga::EvaluationFunctions::OneMaxEval::OneMaxEval() : EvaluationFunction() {}

EvaluationFunction* ndga::EvaluationFunctions::OneMaxEval::clone() const {
    return new OneMaxEval(*this);
}

void ndga::EvaluationFunctions::OneMaxEval::operator()(Individual &individual, Thread &thread) {
    if (!individual.isEvaluated()) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();

        int zeros = 0;
        for (float k : chromosome) {
            zeros += 1 - k;
        }

        individual.getRelevance().setFitness(zeros);
        individual.setEvaluated(true);
    }
}

EvaluationFunction * ndga::EvaluationFunctions::oneMaxEval() {
    return new OneMaxEval();

}

