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

    vector<float> bestFitnesses(unsigned int epoch) const;
    vector<vector<float>> bestFitnesses() const;
    vector<float> averageFitnesses(unsigned int epoch) const;
    vector<vector<float>> averageFitnesses() const;
    vector<float> worstFitnesses(unsigned int epoch) const;
    vector<vector<float>> worstFitnesses() const;

};


#endif //NDEC_STATISTICS_H
