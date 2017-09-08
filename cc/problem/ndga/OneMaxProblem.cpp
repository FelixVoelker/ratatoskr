#include <iostream>
#include "OneMaxProblem.h"
#include "../../ec/ndga/BitVectorIndividual.h"
#include "../../ec/common/RawFitness.h"

/**
 *
 * @param pop_size
 * @param genes
 */
OneMaxProblem::OneMaxProblem(unsigned int pop_size, unsigned int genes) : NDGAProblem(pop_size, genes) {}

void OneMaxProblem::evaluate(Individual &individual) const {
    if (!individual.evaluated()) {
        vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(individual).getChromosome();

        int zeros = 0;
        for (unsigned int k : chromosome)
            zeros += 1 - k;

        dynamic_cast<RawFitness &>(individual.getRelevance().getFitness()).fitness(zeros);
        individual.evaluated(true);
    }
}