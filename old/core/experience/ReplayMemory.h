#ifndef RATATOSKR_REPLAYMEMORY_H
#define RATATOSKR_REPLAYMEMORY_H


#include <vector>
#include "../../../core/state/Individual.h"
#include "../../../core/util/Thread.h"

class ReplayMemory : public Prototype {

public:
    explicit ReplayMemory(const core::Configuration &configuration);
    ~ReplayMemory();

    void record(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings, Thread &thread);

    ReplayMemory * clone() const override;

    bool isReady();

    unsigned int sampleIndex(Thread &thread);

    float getFitnessFromSample(unsigned int index);
    std::vector<float> getParentFromSample(unsigned int index);
    std::vector<float> getOffspringFromSample(unsigned int index);

protected:
    unsigned int chunk_size;

    std::vector<bool> *ready;

    std::vector<unsigned int> *pointer;
    std::vector<unsigned int> *onset;
    std::vector<unsigned int> *offset;

    std::vector<float> *fitness_memory;
    std::vector<std::vector<float>> *parent_memory;
    std::vector<std::vector<float>> *offspring_memory;

    ReplayMemory(const ReplayMemory &obj);

};


#endif //RATATOSKR_REPLAYMEMORY_H
