#ifndef RATATOSKR_STATISTICS_H
#define RATATOSKR_STATISTICS_H


#include "../representation/Population.h"

/**
 * The core module that records a time series of fitness, cost and relevance data that is obtained during a run of a
 * Neuro-Dynamic Evolutionary Algorithm (NDEA). Accordingly, each (epoch, generation) pair maps on a recorded data point
 * that is averaged over the total number of episodes in each epoch.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   3.1.2018
 */
class Statistics {

public:
    explicit Statistics(Configuration &configuration);
    ~Statistics();

    /**
     * Records the fitness value of the best, average and worst individual in the population at each generation and
     * averages it by the total number of episodes in each epoch.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void record(Population &pop, unsigned int epoch, unsigned int generation);

    /**
     * Returns the averaged fitness values of the best individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> bestFitnesses(unsigned int epoch) const;

    /**
     * Returns the averaged fitness values of the average individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> averageFitnesses(unsigned int epoch) const;

    /**
     * Returns the averaged fitness values of the worst individual at each generation.
     * @param epoch Current epoch of the evolutionary run.
     */
    std::vector<float> worstFitnesses(unsigned int epoch) const;

protected:
    unsigned int episodes;

    std::vector<std::vector<float>> best_fitnesses;
    std::vector<std::vector<float>> average_fitnesses;
    std::vector<std::vector<float>> worst_fitnesses;

};


#endif //RATATOSKR_STATISTICS_H
