#include "Statistics.h"

Statistics::Statistics(const core::Configuration &configuration) {
    epochs = configuration.getEvolutionarySystemConfiguration().epochs;
    episodes = configuration.getEvolutionarySystemConfiguration().episodes;
    generations = configuration.getEvolutionarySystemConfiguration().generations;

    auto f = std::vector<float>(generations + 1, 0);
    best_cost = std::vector<std::vector<float>>(epochs, f);
    average_cost = std::vector<std::vector<float>>(epochs, f);
    worst_cost = std::vector<std::vector<float>>(epochs, f);

    best_fitness = std::vector<std::vector<float>>(epochs, f);
    average_fitness = std::vector<std::vector<float>>(epochs, f);
    worst_fitness = std::vector<std::vector<float>>(epochs, f);

    best_relevance = std::vector<std::vector<float>>(epochs, f);
    average_relevance = std::vector<std::vector<float>>(epochs, f);
    worst_relevance = std::vector<std::vector<float>>(epochs, f);

    most_relevant_cost = std::vector<std::vector<float>>(epochs, f);
    least_relevant_cost = std::vector<std::vector<float>>(epochs, f);

    most_relevant_fitness = std::vector<std::vector<float>>(epochs, f);
    least_relevant_fitness = std::vector<std::vector<float>>(epochs, f);
}

Statistics::~Statistics() {
    std::vector<std::vector<float>>().swap(best_cost);
    std::vector<std::vector<float>>().swap(average_cost);
    std::vector<std::vector<float>>().swap(worst_cost);

    std::vector<std::vector<float>>().swap(best_fitness);
    std::vector<std::vector<float>>().swap(average_fitness);
    std::vector<std::vector<float>>().swap(worst_fitness);

    std::vector<std::vector<float>>().swap(best_relevance);
    std::vector<std::vector<float>>().swap(average_relevance);
    std::vector<std::vector<float>>().swap(worst_relevance);

    std::vector<std::vector<float>>().swap(most_relevant_cost);
    std::vector<std::vector<float>>().swap(least_relevant_cost);

    std::vector<std::vector<float>>().swap(most_relevant_fitness);
    std::vector<std::vector<float>>().swap(least_relevant_fitness);
}

void Statistics::record(Population &pop, const unsigned int epoch, const unsigned int generation) {
    recordCost(pop, epoch, generation);
    recordFitness(pop, epoch, generation);
    recordRelevance(pop, epoch, generation);
}

std::vector<float> Statistics::bestCost(unsigned int epoch) const {
    return best_cost.at(epoch);
}

std::vector<float> Statistics::averageCost(unsigned int epoch) const {
    return average_cost.at(epoch);
}

std::vector<float> Statistics::worstCost(unsigned int epoch) const {
    return worst_cost.at(epoch);
}

std::vector<float> Statistics::bestFitness(const unsigned int epoch) const {
    return best_fitness.at(epoch);
}

std::vector<float> Statistics::averageFitness(const unsigned int epoch) const {
    return average_fitness.at(epoch);
}

std::vector<float> Statistics::worstFitness(const unsigned int epoch) const {
    return worst_fitness.at(epoch);
}

std::vector<float> Statistics::bestRelevance(unsigned int epoch) const {
    return best_relevance.at(epoch);
}

std::vector<float> Statistics::averageRelevance(unsigned int epoch) const {
    return average_relevance.at(epoch);
}

std::vector<float> Statistics::worstRelevance(unsigned int epoch) const {
    return worst_relevance.at(epoch);
}

std::vector<float> Statistics::mostRelevantCost(unsigned int epoch) const {
    return most_relevant_cost.at(epoch);
}

std::vector<float> Statistics::leastRelevantCost(unsigned int epoch) const {
    return least_relevant_cost.at(epoch);
}

std::vector<float> Statistics::mostRelevantFitness(unsigned int epoch) const {
    return most_relevant_fitness.at(epoch);
}

std::vector<float> Statistics::leastRelevantFitness(unsigned int epoch) const {
    return least_relevant_fitness.at(epoch);
}

unsigned int Statistics::getEpochs() {
    return epochs;
}

unsigned int Statistics::getEpisodes() {
    return episodes;
}

unsigned int Statistics::getGenerations() {
    return generations;
}

void Statistics::recordCost(Population &pop, unsigned int epoch, unsigned int generation) {
    std::vector<Individual *> individuals = pop.getIndividuals();
    float best = individuals.at(0)->getRelevance().getCost();
    float worst = individuals.at(0)->getRelevance().getCost();
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance().getCost() < best) {
            best = individuals.at(k)->getRelevance().getCost();
        }
        if (individuals.at(k)->getRelevance().getCost() > worst) {
            worst = individuals.at(k)->getRelevance().getCost();
        }
    }

    best_cost.at(epoch).at(generation) += best / episodes;
    average_cost.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().getCost() / episodes;
    worst_cost.at(epoch).at(generation) += worst / episodes;
    most_relevant_cost.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().getCost() / episodes;
    least_relevant_cost.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().getCost() / episodes;
}

void Statistics::recordFitness(Population &pop, unsigned int epoch, unsigned int generation) {
    std::vector<Individual *> individuals = pop.getIndividuals();
    float best = individuals.at(0)->getRelevance().getFitness();
    float worst = individuals.at(0)->getRelevance().getFitness();
    for (unsigned int k = 1; k < individuals.size(); k++) {
        if (individuals.at(k)->getRelevance().getFitness() < best) {
            best = individuals.at(k)->getRelevance().getFitness();
        }
        if (individuals.at(k)->getRelevance().getFitness() > worst) {
            worst = individuals.at(k)->getRelevance().getFitness();
        }
    }

    best_fitness.at(epoch).at(generation) += best / episodes;
    average_fitness.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().getFitness() / episodes;
    worst_fitness.at(epoch).at(generation) += worst / episodes;
    most_relevant_fitness.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().getFitness() / episodes;
    least_relevant_fitness.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().getFitness() / episodes;
}

void Statistics::recordRelevance(Population &pop, unsigned int epoch, unsigned int generation) {
    best_relevance.at(epoch).at(generation) += pop.bestIndividual()->getRelevance().relevance() / episodes;
    average_relevance.at(epoch).at(generation) += pop.averageIndividual()->getRelevance().relevance() / episodes;
    worst_relevance.at(epoch).at(generation) += pop.worstIndividual()->getRelevance().relevance() / episodes;
}