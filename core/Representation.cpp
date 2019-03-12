#include "Representation.h"

Representation::Representation(Genotype &genotype, InitializationOperator &init, std::vector<VariationOperator *> &vary)
: genotype(genotype), init(init), vary(vary) {

}

Genotype& Representation::getGenotype() {
    return genotype;
}

InitializationOperator& Representation::getInitializationOperator() {
    return init;
}

std::vector<VariationOperator *>& Representation::getVariationOperators() {
    return vary;
}