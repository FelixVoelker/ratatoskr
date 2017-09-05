#ifndef NDEC_STATISTICS_H
#define NDEC_STATISTICS_H


#include <boost/python.hpp>
#include "../representation/Population.h"

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   9.8.2017
 */
class Statistics {

private:
    unsigned int episodes;

    vector<vector<float>> best_fitnesses;
    vector<vector<float>> average_fitnesses;
    vector<vector<float>> worst_fitnesses;

    float averageFitness(Population &pop);

public:
    explicit Statistics(Session &session);

    void record(Population &pop, unsigned int epoch, unsigned int generation);

    vector<float> bestFitnesses(int epoch);
    vector<vector<float>> bestFitnesses();
    vector<float> averageFitnesses(int epoch);
    vector<vector<float>> averageFitnesses();
    vector<float> worstFitnesses(int epoch);
    vector<vector<float>> worstFitnesses();

};


#endif //NDEC_STATISTICS_H
