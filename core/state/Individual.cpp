#include "Individual.h"

Individual::Individual(Representation &representation)
{
    this->genotype = dynamic_cast<Genotype *>(representation.getGenotype().clone());
    this->relevance = new Relevance();
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

