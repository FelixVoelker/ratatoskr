#include "SelectionOperator.h"

SelectionOperator::SelectionOperator(Session &session) : VariationSource(session) {}

unsigned long SelectionOperator::expectedSources() const {
    return 0;
}

std::vector<Individual *> SelectionOperator::perform(std::vector<Individual *> &parents, const unsigned int epoch, Thread &thread) const {
    auto selected = std::vector<Individual *>(1);
    selected.at(0) = select(parents, epoch, thread)->clone();
    return selected;
}