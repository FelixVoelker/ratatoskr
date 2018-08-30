#ifndef RATATOSKR_REPLAYER_H
#define RATATOSKR_REPLAYER_H


#include "EvolutionaryNetwork.h"
#include "ReplayMemory.h"

/**
 * TODO: Comments
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Replayer : public Singleton {

public:
    explicit Replayer(const core::Configuration &configuration, EvolutionaryNetwork &network, ReplayMemory &memory);
    ~Replayer();

    void replay() const;

protected:
    unsigned int batch_size;

    std::vector<Thread *> replaythreads;

    /** Components */
    EvolutionaryNetwork &network;
    ReplayMemory &memory;

    void sampleChunk(std::vector<float> &fitness,
                     std::vector<std::vector<float>> &parent,
                     std::vector<std::vector<float>> &offspring,
                     Thread &thread) const;

};


#endif //RATATOSKR_REPLAYER_H
