#include "FitnessProportionateSelection.h"
#include "RawFitness.h"

FitnessProportionateSelection::FitnessProportionateSelection(Session &session) : SelectionOperator(session) {}

vector<Individual *> FitnessProportionateSelection::select(Population &pop, Randomizer &random) {
    vector<Individual *> &individuals = pop.getIndividuals();

    vector<float> fitnesses(individuals.size());
    for (int k = 0; k < individuals.size(); k++) {
        fitnesses.at(k) = dynamic_cast<RawFitness &>(individuals.at(k)->getFitness()).getFitness();
    }

    unsigned long index = random.randomFromDiscreteDistribution(fitnesses);
    vector<Individual *> selected(1);
    selected.at(0) = individuals.at(index);
    return selected;
}