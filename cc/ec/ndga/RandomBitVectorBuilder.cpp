#include <c++/5/random>

#include "RandomBitVectorBuilder.h"
#include "BitVectorIndividual.h"
#include "../../../core/util/Randomizer.h"


RandomBitVectorBuilder::RandomBitVectorBuilder(const NDGASession &session) : Builder(session) {
    random = new Randomizer();
}

RandomBitVectorBuilder::~RandomBitVectorBuilder() {
    delete random;
}

void RandomBitVectorBuilder::initialize(Individual &ind) const {
    vector<unsigned int> &chromosome = dynamic_cast<BitVectorIndividual &>(ind).getChromosome();
    for (unsigned int &k : chromosome) {
        k = random->randomInt(2);
    }
}
