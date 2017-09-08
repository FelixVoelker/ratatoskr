#ifndef NDEC_EVOLUTIONARYNETWORK_H
#define NDEC_EVOLUTIONARYNETWORK_H


#include "../representation/Population.h"

/**
 * @author  Felix Voelker
 * @version 0.1
 * @since   3.9.2017
 */
class EvolutionaryNetwork : public Singleton {

protected:
    vector<vector<float>> *lookup_table;

    float learning_rate;
    float discount_factor;

public:
    explicit EvolutionaryNetwork(const Session &session);

    vector<float> output(Population &pop) const;
    void update(Population &pop, vector<Individual *> old);

};


#endif //NDEC_EVOLUTIONARYNETWORK_H
