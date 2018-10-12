#include "EvaluationFunctions.h"
#include "../common/VectorIndividual.h"

ndga::EvaluationFunctions::OneMaxEval::OneMaxEval() : EvaluationFunction() {}

EvaluationFunction* ndga::EvaluationFunctions::OneMaxEval::clone() const {
    return new OneMaxEval(*this);
}

void ndga::EvaluationFunctions::OneMaxEval::operator()(Individual &individual, Thread &thread) {
    if (!individual.isEvaluated()) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();

        int fitness = 0;
        for (float k : chromosome)
            fitness += 1 - k;

        individual.getRelevance().setFitness(fitness);
        individual.setEvaluated(true);
    }
}

ndga::EvaluationFunctions::NarrowedOneMaxEval::NarrowedOneMaxEval() : EvaluationFunction() {}

EvaluationFunction* ndga::EvaluationFunctions::NarrowedOneMaxEval::clone() const {
    return new NarrowedOneMaxEval(*this);
}

void ndga::EvaluationFunctions::NarrowedOneMaxEval::operator()(Individual &individual, Thread &thread) {
    if (!individual.isEvaluated()) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();

        int fitness = 0;
        for (float k : chromosome)
            fitness += 1 - k;
        if (fitness > 1)
            fitness = 1;

        individual.getRelevance().setFitness(fitness);
        individual.setEvaluated(true);
    }
}

ndga::EvaluationFunctions::DeceptiveOneMaxEval::DeceptiveOneMaxEval() : EvaluationFunction() {}

EvaluationFunction* ndga::EvaluationFunctions::DeceptiveOneMaxEval::clone() const {
    return new DeceptiveOneMaxEval(*this);
}

void ndga::EvaluationFunctions::DeceptiveOneMaxEval::operator()(Individual &individual, Thread &thread) {
    if (!individual.isEvaluated()) {
        std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();

        int fitness = 1;
        int zeroes = 0;
        for (float k : chromosome) {
            fitness += k;
            zeroes += 1 - k;
        }
        if (zeroes == 0)
            fitness = 0;

        individual.getRelevance().setFitness(fitness);
        individual.setEvaluated(true);
    }
}

EvaluationFunction * ndga::EvaluationFunctions::evalOneMax() {
    return new OneMaxEval();
}

EvaluationFunction * ndga::EvaluationFunctions::evalNarrowedOneMax() {
    return new NarrowedOneMaxEval();
}

EvaluationFunction * ndga::EvaluationFunctions::evalDeceptiveOneMax() {
    return new DeceptiveOneMaxEval();
}

