#include "BitVectorMutation.h"
#include "NDGAProblem.h"
#include "NDGASession.h"
#include "BitVectorIndividual.h"

unsigned long BitVectorMutation::expectedSources() { return 1; }

BitVectorMutation::BitVectorMutation(Session &session)
        : BreedingOperator(session) {
    prob = dynamic_cast<NDGASession &>(session).mutation_rate;
    genes = dynamic_cast<NDGAProblem &>(session.problem()).genes;
}

vector<Individual *> BitVectorMutation::breed(vector<Individual *> parents, Randomizer &random) {
    vector<Individual *> offsprings(parents.size());
    parents.at(0)->toString();

    for (int p = 0; p < parents.size(); p++) {
        auto offspring = dynamic_cast<BitVectorIndividual *>(parents.at(p))->clone();

        for (int k = 0; k < genes; k++) {
            if (random.random() < prob) {
                offspring->getChromosome().at(k) = 1 - offspring->getChromosome().at(k);
                offspring->evaluated = false;
            }
        }

        offsprings.at(p) = offspring;
    }
    return offsprings;
}