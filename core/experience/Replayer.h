#ifndef NDEC_REPLAYER_H
#define NDEC_REPLAYER_H


#include "../evaluation/EvolutionaryNetwork.h"

/**
 * TODO: Comments
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   3.9.2017
 */
class Replayer : public Singleton {

protected:
    EvolutionaryNetwork *network;

public:
    explicit Replayer(const Session &session);

    void replay(Population &pop, vector<Individual *> &offsprings) const;

};


#endif //NDEC_REPLAYER_H
