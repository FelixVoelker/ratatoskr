#include "BitVectorMutation.h"
#include "BitVectorIndividual.h"

unsigned long BitVectorMutation::expectedSources() const { return 1; }

BitVectorMutation::BitVectorMutation(const NDGASession &session)
        : BreedingOperator(session) {
    prob = session.mutation_rate;
    genes = dynamic_cast<const NDGAProblem &>(session.getProblem()).genes;
}

vector<Individual *> & BitVectorMutation::breed(vector<Individual *> &parents, Randomizer &random) const {
    for (auto parent : parents) {
        for (unsigned int k = 0; k < genes; k++) {
            if (random.random() < prob) {
                auto p = dynamic_cast<BitVectorIndividual *>(parent);
                p->getChromosome().at(k) = 1 - p->getChromosome().at(k);
                p->evaluated(false);
            }
        }
    }
    return parents;
}