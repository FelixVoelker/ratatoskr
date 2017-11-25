#include <iostream>
#include "OneMaxProblem.h"
#include "../../ec/ndga/BitVectorIndividual.h"

OneMaxProblem::OneMaxProblem(unsigned int pop_size, unsigned int genes) : NDGAProblem(pop_size, genes) {}

void OneMaxProblem::evaluate(Individual &individual) const {
    if (!individual.evaluated()) {
        vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(individual).getChromosome();

        int zeros = 0;
        for (unsigned int k : chromosome)
            zeros += 1 - k;

        individual.getRelevance().getFitness().fitness(zeros);
        individual.evaluated(true);
    }
}