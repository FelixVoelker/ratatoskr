#include "FitnessProportionateSelection.h"

FitnessProportionateSelection::FitnessProportionateSelection(const common::Configuration &configuration)
        : SelectionOperator(configuration)
{
    this->epochs = configuration.getEvolutionarySystemConfiguration().epochs;
}

Individual * FitnessProportionateSelection::select(std::vector<Individual *> &parents, Thread &thread) const {
    std::vector<float> relevances(parents.size());
    for (int k = 0; k < parents.size(); k++) {
        relevances.at(k) = parents.at(k)->relevance(((float) thread.getEpoch()) / epochs);
    }

    unsigned long index = thread.random.sampleIntFromDiscreteDistribution(relevances);
    return parents.at(index);
}