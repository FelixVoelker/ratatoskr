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

void OneMaxProblem::evaluate(Individual &individual) {
    vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(individual).getChromosome();

    int ones = 0;
    for (int k = 0; k < chromosome.size(); k++) {
        ones += chromosome.at(k);
    }

    dynamic_cast<RawFitness &>(individual.getFitness()).setFitness(ones);
}
