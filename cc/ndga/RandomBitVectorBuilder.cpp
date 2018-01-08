#include <c++/5/random>

#include "RandomBitVectorBuilder.h"
#include "../common/VectorIndividual.h"
#include "../../core/util/Thread.h"


RandomBitVectorBuilder::RandomBitVectorBuilder(const NDGASession &session) : Builder(session) {
    random = new Thread();
}

RandomBitVectorBuilder::~RandomBitVectorBuilder() {
    delete random;
}

void RandomBitVectorBuilder::initialize(Individual &ind) const {
    vector<unsigned int> &chromosome = dynamic_cast<VectorIndividual &>(ind).getChromosome();
    for (unsigned int &k : chromosome) {
        k = random->randomInt(2);
    }
}
