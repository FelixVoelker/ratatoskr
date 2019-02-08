#ifndef RATATOSKR_GENETICALGORITHM_H
#define RATATOSKR_GENETICALGORITHM_H


#include "../../../../core/old/EvolutionarySystem.h"
#include "../representation/vector/Vector.h"
#include "../representation/vector/binary/RandomBinaryVectorBuilder.h"
#include "../representation/vector/binary/BinaryVectorMutation.h"
#include "../representation/vector/binary/BinaryVectorCrossover.h"

/**
 * @author  FelixVoelker
 * @version 0.1.1
 * @since   12.7.2018
 */
class GeneticAlgorithm : public EvolutionarySystem {

public:
    GeneticAlgorithm(unsigned int popsize, unsigned int genes);

protected:
    // Representation
    Vector *genotype;
    RandomBinaryVectorBuilder *builder;
    BinaryVectorMutation *mutation;
    BinaryVectorCrossover *crossover;


};


#endif //RATATOSKR_GENETICALGORITHM_H
