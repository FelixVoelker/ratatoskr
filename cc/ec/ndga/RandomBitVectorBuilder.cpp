#include <c++/5/random>

#include "RandomBitVectorBuilder.h"
#include "BitVectorIndividual.h"
#include "../../../core/util/Randomizer.h"


RandomBitVectorBuilder::RandomBitVectorBuilder(const NDGASession &session) : Builder(session) {}

void RandomBitVectorBuilder::initialize(Individual &ind) const {
    //Randomizer r;
    vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(ind).getChromosome();
    for (unsigned int &k : chromosome) {
        k = 0/*r.randomInt(2)*/;
    }
}
