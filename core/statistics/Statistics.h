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
    vector<float> best_fitnesses;
    vector<float> average_fitnesses;
    vector<float> worst_fitnesses;

    float averageFitness(Population &pop);

public:
    explicit Statistics(Session &session);

    void record(Population &pop, unsigned int generation);

    vector<float> bestFitnesses();
    vector<float> averageFitnesses();
    vector<float> worstFitnesses();
};


#endif //NDEC_STATISTICS_H
