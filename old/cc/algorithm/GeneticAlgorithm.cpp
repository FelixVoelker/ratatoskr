#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(unsigned int popsize, unsigned int genes) : EvolutionarySystem() {
    // Representation
    genotype = new Vector(genes);
    builder = new RandomBinaryVectorBuilder();
    mutation = new BinaryVectorMutation();
    crossover = new BinaryVectorCrossover();

    initializer
}