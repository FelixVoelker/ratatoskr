#ifndef RATATOSKR_STATISTICS_H
#define RATATOSKR_STATISTICS_H


#include "../../state/Population.h"

/**
 * The core module that records a time series of fitness, cost and relevance data that is obtained during a run of a
 * Neuro-Dynamic Evolutionary Algorithm (NDEA). Accordingly, each (epoch, generation) pair maps on a recorded data point
 * that is averaged over the total number of episodes in each epoch.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Statistics {

public:
    explicit Statistics();
    ~Statistics();

    /**
     * Records all relevant data for the statistic.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void record(Population &pop, unsigned int epoch, unsigned int generation);

    /**
     * Returns the best cost values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> bestCost(unsigned int epoch) const;

    /**
     * Returns the average cost values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> averageCost(unsigned int epoch) const;

    /**
     * Returns the worst cost values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> worstCost(unsigned int epoch) const;

    /**
     * Returns the best fitness values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> bestFitness(unsigned int epoch) const;

    /**
     * Returns the average fitness values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> averageFitness(unsigned int epoch) const;

    /**
     * Returns the worst fitness values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> worstFitness(unsigned int epoch) const;

    /**
     * Returns the best relevance values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> bestRelevance(unsigned int epoch) const;

    /**
     * Returns the average relevance values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> averageRelevance(unsigned int epoch) const;

    /**
     * Returns the worst relevance values for each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> worstRelevance(unsigned int epoch) const;

    /**
     * Returns the cost values of the individuals with the best relevance at each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> mostRelevantCost(unsigned int epoch) const;

    /**
     * Returns the cost values of the individuals with the worst relevance at each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> leastRelevantCost(unsigned int epoch) const;

    /**
     * Returns the fitness values of the individuals with the best relevance at each generation.
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> mostRelevantFitness(unsigned int epoch) const;

    /**
     * Returns the fitness values of the individuals with the worst relevance at each generation
     * @param epoch Requested epoch of the evolutionary run.
     */
    std::vector<float> leastRelevantFitness(unsigned int epoch) const;

    unsigned int getEpochs();
    unsigned int getEpisodes();
    unsigned int getGenerations();

protected:
    unsigned int epochs;
    unsigned int episodes;
    unsigned int generations;

    std::vector<std::vector<float>> best_cost;
    std::vector<std::vector<float>> average_cost;
    std::vector<std::vector<float>> worst_cost;

    std::vector<std::vector<float>> best_fitness;
    std::vector<std::vector<float>> average_fitness;
    std::vector<std::vector<float>> worst_fitness;

    std::vector<std::vector<float>> best_relevance;
    std::vector<std::vector<float>> average_relevance;
    std::vector<std::vector<float>> worst_relevance;

    std::vector<std::vector<float>> most_relevant_cost;
    std::vector<std::vector<float>> least_relevant_cost;

    std::vector<std::vector<float>> most_relevant_fitness;
    std::vector<std::vector<float>> least_relevant_fitness;

    /**
     * Records the best, average and worst cost values of the population as well as the cost of the individuals with
     * the highest and lowest relevance values in the population at each generation and averages it by the total number
     * of episodes in each epoch.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void recordCost(Population &pop, unsigned int epoch, unsigned int generation);

    /**
     * Records the best, average and worst fitness values of the population as well as the fitness of the individuals
     * with the highest and lowest relevance values in the population at each generation and averages it by the total
     * number of episodes in each epoch.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void recordFitness(Population &pop, unsigned int epoch, unsigned int generation);

    /**
     * Records the best, average and worst relevance values of the population as well as the relevance of the
     * individuals with the highest and lowest relevance values in the population at each generation and averages it by
     * the total number of episodes in each epoch.
     * @param pop State of evolutionary system's population.
     * @param epoch Current epoch of the evolutionary run.
     * @param generation Current generation of the evolutionary run.
     */
    void recordRelevance(Population &pop, unsigned int epoch, unsigned int generation);

};


#endif //RATATOSKR_STATISTICS_H
