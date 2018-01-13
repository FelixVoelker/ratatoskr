#ifndef RATATOSKR_REPLAYER_H
#define RATATOSKR_REPLAYER_H


#include "EvolutionaryNetwork.h"

/**
 * TODO: Comments
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   3.1.2018
 */
class Replayer : public Singleton {

public:
    explicit Replayer(const core::Configuration &configuration, EvolutionaryNetwork *network);

    void replay(Population &pop, std::vector<Individual *> &offsprings) const;

protected:
    EvolutionaryNetwork *network;

};


#endif //RATATOSKR_REPLAYER_H
