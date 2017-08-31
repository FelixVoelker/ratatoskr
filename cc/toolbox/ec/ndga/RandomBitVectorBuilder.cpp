#include <c++/5/random>

#include "RandomBitVectorBuilder.h"
#include "BitVectorIndividual.h"
#include "../../../../core/util/Randomizer.h"


RandomBitVectorBuilder::RandomBitVectorBuilder(NDGASession &session) : Builder(session) {}

void RandomBitVectorBuilder::initialize(Individual &ind) {
    Randomizer r;
    vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(ind).getChromosome();
    for (unsigned int &k : chromosome) {
        k = r.randomInt(2);
    }
}
