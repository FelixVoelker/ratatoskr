#include "Configuration.h"

core::Configuration::ProblemConfiguration::ProblemConfiguration(const ProblemConfiguration &obj) {
    this->popsize = obj.popsize;
}

core::Configuration::EvolutionarySystemConfiguration::EvolutionarySystemConfiguration(const EvolutionarySystemConfiguration &obj) {
    this->complete = obj.complete;
    this->generations = obj.generations;
    this->episodes = obj.episodes;
    this->epochs = obj.epochs;
}

core::Configuration::InitializerConfiguration::InitializerConfiguration(const InitializerConfiguration &obj) {
    this->threads = obj.threads;
}

core::Configuration::EvaluatorConfiguration::EvaluatorConfiguration(const EvaluatorConfiguration &obj) {
    this->threads = obj.threads;
}

core::Configuration::BreederConfiguration::BreederConfiguration(const BreederConfiguration &obj) {
    this->threads = obj.threads;
}

core::Configuration::EvolutionaryNetworkConfiguration::EvolutionaryNetworkConfiguration(const EvolutionaryNetworkConfiguration &obj) {
    this->learning_rate = obj.learning_rate;
    this->discount_factor = obj.discount_factor;
}

core::Configuration::Configuration(const ProblemConfiguration &problem) : problem(problem) {}

core::Configuration::Configuration(const Configuration &obj) : problem(obj.problem) {
    evolutionary_system = EvolutionarySystemConfiguration(obj.evolutionary_system);
    initializer = InitializerConfiguration(obj.initializer);
    evaluator = EvaluatorConfiguration(obj.evaluator);
    breeder = BreederConfiguration(obj.breeder);
    evolutionary_network = EvolutionaryNetworkConfiguration(obj.evolutionary_network);
}

const core::Configuration::ProblemConfiguration& core::Configuration::getProblemConfiguration() const {
   return problem;
}

core::Configuration::EvolutionarySystemConfiguration & core::Configuration::getEvolutionarySystemConfiguration() {
    return evolutionary_system;
}

const core::Configuration::EvolutionarySystemConfiguration & core::Configuration::getEvolutionarySystemConfiguration() const {
    return evolutionary_system;
}

core::Configuration::InitializerConfiguration & core::Configuration::getInitializerConfiguration() {
    return initializer;
}

const core::Configuration::InitializerConfiguration & core::Configuration::getInitializerConfiguration() const {
    return initializer;
}

core::Configuration::EvaluatorConfiguration & core::Configuration::getEvaluatorConfiguration() {
    return evaluator;
}

const core::Configuration::EvaluatorConfiguration & core::Configuration::getEvaluatorConfiguration() const {
    return evaluator;
}

core::Configuration::BreederConfiguration & core::Configuration::getBreederConfiguration() {
    return breeder;
}

const core::Configuration::BreederConfiguration & core::Configuration::getBreederConfiguration() const {
    return breeder;
}

core::Configuration::EvolutionaryNetworkConfiguration & core::Configuration::getEvolutionaryNetworkConfiguration() {
    return evolutionary_network;
}

const core::Configuration::EvolutionaryNetworkConfiguration & core::Configuration::getEvolutionaryNetworkConfiguration() const {
    return evolutionary_network;
}
