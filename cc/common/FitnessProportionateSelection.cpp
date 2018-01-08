#include "FitnessProportionateSelection.h"

FitnessProportionateSelection::FitnessProportionateSelection(common::Configuration &configuration)
        : SelectionOperator(configuration)
{
    this->epochs = configuration.getEvolutionarySystemConfiguration().epochs;
}

Individual * FitnessProportionateSelection::select(std::vector<Individual *> &parents, Thread &thread) const {
    std::vector<float> fitnesses(parents.size());
    for (int k = 0; k < parents.size(); k++) {
        fitnesses.at(k) = parents.at(k)->relevance(((float) thread.getEpoch()) / epochs);
    }

    unsigned long index = thread.random.sampleIntFromDiscreteDistribution(fitnesses);
    return parents.at(index);
}