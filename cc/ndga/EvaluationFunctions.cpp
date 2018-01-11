#include "EvaluationFunctions.h"

std::function<void(Individual &, Thread &)> ndga::EvaluationFunctions::OneMaxProblem::operator()() {
    std::function<void(Individual &, Thread &)> eval = [](Individual &individual, Thread &thread) {
        if (!individual.isEvaluated()) {
            std::vector<float> &chromosome = dynamic_cast<VectorIndividual &>(individual).getChromosome();

            int zeros = 0;
            for (float k : chromosome) {
                zeros += 1 - k;
            }

            individual.getFitness().setFitness(zeros);
            individual.setEvaluated(true);
        }
    };

    return eval;
}