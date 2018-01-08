#include "SelectionOperator.h"

SelectionOperator::SelectionOperator(Configuration &configuration) : VariationSource(configuration) {}

unsigned long SelectionOperator::expectedSources() const {
    return 0;
}

std::vector<Individual *> SelectionOperator::perform(std::vector<Individual *> &parents, Thread &thread) const {
    auto selected = std::vector<Individual *>(1);
    selected.at(0) = select(parents, thread)->clone();
    return selected;
}