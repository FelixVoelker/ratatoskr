#ifndef RATATOSKR_STATISTICS_H
#define RATATOSKR_STATISTICS_H


#include "../representation/Population.h"

/**
 * The core module that records a time series of fitness, cost and relevance data that is obtained during a run of a
 * Neuro-Dynamic Evolutionary Algorithm (NDEA). Accordingly, each (epoch, generation) pair maps on a recorded data point
 * that is averaged over the total number of episodes in each epoch.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class Statistics {

public:
    explicit Statistics(const core::Configuration &configuration);
    ~Statistics();

    /**
     * Records the cost, fitness and relevance value of the best, average and worst individual in the population at each
     * generation and averages it by the total number of episodes in each epoch.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void record(Population &pop, unsigned int epoch, unsigned int generation);

    /**
     * Returns the averaged cost values of the best individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> bestCosts(unsigned int epoch) const;

    /**
     * Returns the averaged fitness values of the best individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> bestFitnesses(unsigned int epoch) const;

    /**
     * Returns the averaged relevance values of the best individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> bestRelevances(unsigned int epoch) const;

    /**
     * Returns the averaged cost values of the average individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> averageCosts(unsigned int epoch) const;

    /**
     * Returns the averaged fitness values of the average individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> averageFitnesses(unsigned int epoch) const;

    /**
     * Returns the averaged relevance values of the average individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> averageRelevances(unsigned int epoch) const;

    /**
     * Returns the averaged cost values of the worst individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> worstCosts(unsigned int epoch) const;

    /**
     * Returns the averaged fitness values of the worst individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> worstFitnesses(unsigned int epoch) const;

    /**
     * Returns the averaged relevance values of the worst individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> worstRelevances(unsigned int epoch) const;

protected:
    unsigned int epochs;
    unsigned int episodes;

    std::vector<std::vector<float>> best_costs;
    std::vector<std::vector<float>> best_fitnesses;
    std::vector<std::vector<float>> best_relevances;
    std::vector<std::vector<float>> average_costs;
    std::vector<std::vector<float>> average_fitnesses;
    std::vector<std::vector<float>> average_relevances;
    std::vector<std::vector<float>> worst_costs;
    std::vector<std::vector<float>> worst_fitnesses;
    std::vector<std::vector<float>> worst_relevances;

};


#endif //RATATOSKR_STATISTICS_H
