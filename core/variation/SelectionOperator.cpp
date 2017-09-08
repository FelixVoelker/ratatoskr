#include "SelectionOperator.h"

SelectionOperator::SelectionOperator(const Session &session) : VariationSource(session) {}

unsigned long SelectionOperator::expectedSources() const {
    return 0;
}

vector<Individual *> SelectionOperator::perform(vector<Individual *> &parents, const unsigned int epoch, Randomizer &random) const {
    vector<Individual *> selected = select(parents, epoch, random);
    for (int k = 0; k < selected.size(); k++) {
        selected.at(k) = dynamic_cast<Individual *>(selected.at(k)->clone());
    }
    return selected;
}