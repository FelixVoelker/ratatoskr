#include "Session.h"
#include "BitVectorCrossover.h"
#include "../common/FitnessProportionateSelection.h"

ndga::Session::Session(const common::Problem &problem)
        : core::Session(problem, new common::Configuration(dynamic_cast<const common::Configuration::ProblemConfiguration &>(problem.getConfiguration())))
{

}

ndga::Session::Session(const common::Problem &problem, common::Configuration *config) : core::Session(problem, config) {}

EvolutionarySystem* ndga::Session::build() {
    RandomBitVectorBuilder *builder = constructDefaultBuilder();
    TransitionTable *network = constructDefaultNetwork();
    BreedingOperator *variation_tree = constructDefaultVariation();
    EvolutionarySystem *system = core::Session::build(*builder, *network, *variation_tree);
    delete builder;
    delete network;
    delete variation_tree;
    return system;
}

EvolutionarySystem* ndga::Session::build(RandomBitVectorBuilder &builder) {
    TransitionTable *network = constructDefaultNetwork();
    BreedingOperator *variation_tree = constructDefaultVariation();
    EvolutionarySystem *system = core::Session::build(builder, *network, *variation_tree);
    delete network;
    delete variation_tree;
    return system;
}

EvolutionarySystem* ndga::Session::build(TransitionTable &network) {
    RandomBitVectorBuilder *builder = constructDefaultBuilder();
    BreedingOperator *variation_tree = constructDefaultVariation();
    EvolutionarySystem *system = core::Session::build(*builder, network, *variation_tree);
    delete builder;
    delete variation_tree;
    return system;
}

EvolutionarySystem* ndga::Session::build(BreedingOperator &variation_tree) {
    RandomBitVectorBuilder *builder = constructDefaultBuilder();
    TransitionTable *network = constructDefaultNetwork();
    EvolutionarySystem *system = core::Session::build(*builder, *network, variation_tree);
    delete builder;
    delete network;
    return system;
}

EvolutionarySystem* ndga::Session::build(RandomBitVectorBuilder &builder, TransitionTable &network) {
    BreedingOperator *variation_tree = constructDefaultVariation();
    EvolutionarySystem *system = core::Session::build(builder, network, *variation_tree);
    delete variation_tree;
    return system;
}

EvolutionarySystem* ndga::Session::build(RandomBitVectorBuilder &builder, BreedingOperator &variation_tree) {
    TransitionTable *network = constructDefaultNetwork();
    EvolutionarySystem *system = core::Session::build(builder, *network, variation_tree);
    delete network;
    return system;
}

EvolutionarySystem* ndga::Session::build(TransitionTable &network, BreedingOperator &variation_tree) {
    RandomBitVectorBuilder *builder = constructDefaultBuilder();
    EvolutionarySystem *system = core::Session::build(*builder, network, variation_tree);
    delete builder;
    return system;
}

RandomBitVectorBuilder * ndga::Session::constructDefaultBuilder() {
    auto *config = dynamic_cast<common::Configuration *>(configuration);
    auto *featuremap = new FeatureVector(*config);
    auto *relevance = new Relevance(*configuration);
    auto *individual = new VectorIndividual(*config, *featuremap, *relevance);
    auto *builder = new RandomBitVectorBuilder(*config, *individual);
    delete individual;
    delete relevance;
    delete featuremap;
    return builder;
}

TransitionTable * ndga::Session::constructDefaultNetwork() {
    auto *config = dynamic_cast<common::Configuration *>(configuration);
    return new TransitionTable(*config);
}

BitVectorMutation * ndga::Session::constructDefaultVariation() {
    auto *config = dynamic_cast<common::Configuration *>(configuration);
    auto selector1 = new FitnessProportionateSelection(*config);
    selector1->setup(new std::vector<VariationSource *>(0));
    auto *selector2 = new FitnessProportionateSelection(*config);
    selector2->setup(new std::vector<VariationSource *>(0));
    auto *crossover = new BitVectorCrossover(*config);
    crossover->setup(new std::vector<VariationSource *>({ selector1, selector2 }));
    auto *mutation = new BitVectorMutation(*config);
    mutation->setup(new std::vector<VariationSource *>({ crossover }));
    return mutation;
}