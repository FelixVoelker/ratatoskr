#include "Thread.h"

Thread::Thread(unsigned int *epoch, unsigned int onset, unsigned int offset) {
    this->epoch = epoch;
    this->onset = onset;
    this->offset = offset;
}

unsigned int & Thread::getEpoch() const {
    return *epoch;
}

unsigned int Thread::getChunkOnset() const {
    return onset;
}

unsigned int Thread::getChunkOffset() const {
    return offset;
}

double Thread::Random::sample() {
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    return distribution(generator);
}

unsigned int Thread::Random::sampleIntFromUniformDistribution(unsigned int n) {
    std::uniform_int_distribution<unsigned int> distribution(0, n - 1);
    return distribution(generator);
}

unsigned int Thread::Random::sampleIntFromDiscreteDistribution(std::vector<float> weights) {
    std::discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
    return distribution(generator);
}