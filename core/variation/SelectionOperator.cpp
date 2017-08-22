#include "SelectionOperator.h"

SelectionOperator::SelectionOperator(Session &session) : VariationSource(session) {}

unsigned long SelectionOperator::expectedSources() {
    return 0;
}

vector<Individual *> SelectionOperator::perform(Population &pop, vector<Individual *> parents, Randomizer &random) {
    vector<Individual *> selected = select(pop, random);
    for (int k = 0; k < selected.size(); k++) {
        selected.at(0) = dynamic_cast<Individual *>(selected.at(0)->clone());
    }
    return selected;
}