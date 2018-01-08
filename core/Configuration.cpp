#include "Configuration.h"

Configuration::ProblemConfiguration::ProblemConfiguration(const ProblemConfiguration &obj) {
    this->popsize = obj.popsize;
}

Configuration::EvolutionarySystemConfiguration::EvolutionarySystemConfiguration(const EvolutionarySystemConfiguration &obj) {
    this->complete = obj.complete;
    this->generations = obj.generations;
    this->episodes = obj.episodes;
    this->epochs = obj.epochs;
}

Configuration::InitializerConfiguration::InitializerConfiguration(const InitializerConfiguration &obj) {
    this->threads = obj.threads;
}

Configuration::EvaluatorConfiguration::EvaluatorConfiguration(const EvaluatorConfiguration &obj) {
    this->threads = obj.threads;
}

Configuration::BreederConfiguration::BreederConfiguration(const BreederConfiguration &obj) {
    this->threads = obj.threads;
}

Configuration::EvolutionaryNetworkConfiguration::EvolutionaryNetworkConfiguration(const EvolutionaryNetworkConfiguration &obj) {
    this->learning_rate = obj.learning_rate;
    this->discount_factor = obj.discount_factor;
}

Configuration::Configuration(ProblemConfiguration &problem) : problem(problem) {}

Configuration::Configuration(const Configuration &obj) : problem(obj.problem) {
    evolutionary_system = EvolutionarySystemConfiguration(obj.evolutionary_system);
    initializer = InitializerConfiguration(obj.initializer);
    evaluator = EvaluatorConfiguration(obj.evaluator);
    breeder = BreederConfiguration(obj.breeder);
    evolutionary_network = EvolutionaryNetworkConfiguration(obj.evolutionary_network);
}

Configuration::ProblemConfiguration& Configuration::getProblemConfiguration() const {
   return problem;
}

Configuration::EvolutionarySystemConfiguration & Configuration::getEvolutionarySystemConfiguration() {
    return evolutionary_system;
}

Configuration::InitializerConfiguration & Configuration::getInitializerConfiguration() {
    return initializer;
}

Configuration::EvaluatorConfiguration & Configuration::getEvaluatorConfiguration() {
    return evaluator;
}

Configuration::BreederConfiguration & Configuration::getBreederConfiguration() {
    return breeder;
}

Configuration::EvolutionaryNetworkConfiguration & Configuration::getEvolutionaryNetworkConfiguration() {
    return evolutionary_network;
}
