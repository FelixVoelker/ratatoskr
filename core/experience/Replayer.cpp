#include <thread>
#include "Replayer.h"

Replayer::Replayer(const core::Configuration &configuration, EvolutionaryNetwork &network, ReplayMemory &memory)
        : Singleton(configuration),
          network(network),
          memory(memory),
          replaythreads(std::vector<Thread *>(configuration.getReplayerConfiguration().threads))
{
    this->batch_size = configuration.getReplayerConfiguration().batch_size;
    unsigned int onset = 0;
    unsigned int offset = batch_size / configuration.getReplayerConfiguration().threads;
    for (unsigned int k = 0; k < replaythreads.size() - 1; k++) {
        replaythreads.at(k) = new Thread(k, onset, offset);
        onset += offset;
    }
    replaythreads.at(replaythreads.size() - 1) = new Thread(replaythreads.size() - 1, onset, batch_size - onset);
}

Replayer::~Replayer() {
    for (auto *thread : replaythreads)
        delete thread;
    std::vector<Thread *>().swap(replaythreads);
}

void Replayer::replay() const {
    auto fitness = std::vector<float>(batch_size);
    auto parent = std::vector<std::vector<float>>(batch_size);
    auto offspring = std::vector<std::vector<float>>(batch_size);

    std::vector<std::thread> threads(replaythreads.size());
    for (unsigned int k = 0; k < replaythreads.size(); k++) {
        threads.at(k) = std::thread(&Replayer::sampleChunk, this, std::ref(fitness), std::ref(parent),
                                    std::ref(offspring), std::ref(*replaythreads.at(k)));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    if (memory.isReady())
        network.update(fitness, parent, offspring);
}

void Replayer::sampleChunk(std::vector<float> &fitness,
                           std::vector<std::vector<float>> &parent,
                           std::vector<std::vector<float>> &offspring,
                           Thread &thread) const
{
    for (unsigned int k = thread.getChunkOnset(); k < thread.getChunkOffset(); k++) {
        unsigned int index = memory.sampleIndex(thread);
        fitness.at(k) = memory.getFitnessFromSample(index);
        parent.at(k) = memory.getParentFromSample(index);
        offspring.at(k) = memory.getOffspringFromSample(index);
    }
}