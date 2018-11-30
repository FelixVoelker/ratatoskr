#include "Thread.h"

Thread::Thread(unsigned int id, unsigned int onset, unsigned int offset) {
    this->id = id;
    this->onset = onset;
    this->offset = offset;
}

unsigned int Thread::getID() const {
    return id;
}

unsigned int Thread::getChunkOnset() const {
    return onset;
}

unsigned int Thread::getChunkOffset() const {
    return offset;
}

std::vector<int> Thread::Random::choose(int a, int b, std::vector<float> weights, unsigned int k) {
    auto sequence = std::vector<int>();
    for (int i = a; i < b; i++) {
        sequence.push_back(i);
    }
    return choose(sequence, weights, k);
}

std::vector<T> Thread::Random::choose(std::vector<T> sequence, std::vector<float> weights, unsigned int k) {
    auto result = std::vector<T>();
    for (unsigned int l = 0; l < k; l++) {
        if (weights = null) {
            std::uniform_int_distribution<unsigned int> distribution(0, sequence.size());
            unsigned int index = distribution(generator);
            result.push_back(sequence.at(index));
        } else {
            std::discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
            unsigned int index = distribution(generator);
            result.push_back(sequence.at(index));
        }
    }
    return result;
}

std::vector<int> Thread::Random::sample(int a, int b, std::vector<float> weights, unsigned int k) {
    auto sequence = std::vector<int>();
    for (int i = a; i < b; i++) {
        sequence.push_back(i);
    }
    return sample(sequence, weights, k);
}

std::vector<T> Thread::Random::sample(std::vector<T> sequence, std::vector<float> weights, unsigned int k) {
    auto result = std::vector<T>();
    for (unsigned int l = 0; l < k; l++) {
        if (weights = null) {
            std::uniform_int_distribution<unsigned int> distribution(0, sequence.size());
            unsigned int index = distribution(generator);
            result.push_back(sequence.at(index));
            sequence.erase(sequence.begin() + index);
        } else {
            std::discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
            unsigned int index = distribution(generator);
            result.push_back(sequence.at(index));
            sequence.erase(sequence.begin() + index);
            weights.erase(weights.begin() + index);
        }
    }
    return result;
}