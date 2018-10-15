#include "Individual.h"

Individual::Individual(Genotype &genotype, Relevance &relevance)
{
    this->genotype = dynamic_cast<Genotype *>(genotype.clone());
    this->relevance = relevance.clone();
}

Individual::Individual(const Individual &obj) {
    genotype = dynamic_cast<Genotype *>(obj.genotype->clone());
    relevance = obj.relevance->clone();
}

Individual::~Individual() {
    delete genotype;
    delete relevance;
}

Genotype & Individual::getGenotype() const {
    return *genotype;
}

Relevance & Individual::getRelevance() const {
    return *relevance;
}

