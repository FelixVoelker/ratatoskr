#include "FitnessProportionateSelection.h"
#include "RawRelevance.h"
#include "RawFitness.h"

FitnessProportionateSelection::FitnessProportionateSelection(const Session &session) : SelectionOperator(session) {}

vector<Individual *> FitnessProportionateSelection::select(const vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const {
    vector<float> fitnesses(parents.size());
    for (int k = 0; k < parents.size(); k++) {
        fitnesses.at(k) = dynamic_cast<RawRelevance &>(parents.at(k)->getRelevance()).relevance(epoch);
    }

    unsigned long index = random.randomFromDiscreteDistribution(fitnesses);
    auto selected = vector<Individual *>(1);
    selected.at(0) = parents.at(index);
    return selected;
}