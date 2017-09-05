#include "FitnessProportionateSelection.h"
#include "RawRelevance.h"

FitnessProportionateSelection::FitnessProportionateSelection(Session &session) : SelectionOperator(session) {}

vector<Individual *> FitnessProportionateSelection::select(Population &pop, unsigned int epoch, Randomizer &random) {
    vector<Individual *> &individuals = pop.getIndividuals();

    vector<float> fitnesses(individuals.size());
    for (int k = 0; k < individuals.size(); k++) {
        fitnesses.at(k) = dynamic_cast<RawRelevance &>(individuals.at(k)->getRelevance()).relevance(epoch);
    }

    unsigned long index = random.randomFromDiscreteDistribution(fitnesses);
    vector<Individual *> selected(1);
    selected.at(0) = individuals.at(index);
    return selected;
}