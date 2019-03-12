#include <iostream>
#include "RandomChoice.h"

float RandomChoice::random(Thread &thread) {
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    return distribution(thread.generator);
}

std::vector<int> RandomChoice::choose(int a, int b, Thread &thread, unsigned int n) {
    int lower = a <= b? a : b;
    int upper = a <= b? b : a;

    auto sequence = std::vector<int>();
    for (int k = lower; k < upper; k++) {
        sequence.push_back(k);
    }
    return choose(sequence, thread, n);
}

template<typename T> std::vector<T> RandomChoice::choose(std::vector<T> sequence, Thread &thread, unsigned int n) {
    auto result = std::vector<T>();
    for (unsigned int k = 0; k < n; k++) {
        std::uniform_int_distribution<unsigned long> distribution(0, sequence.size() - 1);
        unsigned long index = distribution(thread.generator);
        result.push_back(sequence.at(index));
    }
    return result;
}

template<typename T> std::vector<T> RandomChoice::choose(std::vector<T> sequence, std::vector<float> weights, Thread &thread, unsigned int n) {
    try {
        if (sequence.size() != weights.size()) {
            throw RandomChoiceException(sequence.size(), weights.size());
        }

        auto result = std::vector<T>();
        for (unsigned int k = 0; k < n; k++) {
            std::discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
            unsigned int index = distribution(thread.generator);
            result.push_back(sequence.at(index));
        }
        return result;
    } catch (RandomChoiceException &exception) {
        std::cout << exception.what() << std::endl;
        exit(1);
    }
}

std::vector<int> RandomChoice::sample(int a, int b, Thread &thread, unsigned int n) {
    int lower = a <= b? a : b;
    int upper = a <= b? b : a;

    auto sequence = std::vector<int>();
    for (int k = lower; k < upper; k++) {
        sequence.push_back(k);
    }
    return sample(sequence, thread, n);
}

template<typename T> std::vector<T> RandomChoice::sample(std::vector<T> sequence, Thread &thread, unsigned int n) {
    auto result = std::vector<T>();
    for (unsigned int k = 0; k < n; k++) {
        std::uniform_int_distribution<unsigned long> distribution(0, sequence.size() - 1);
        unsigned long index = distribution(thread.generator);
        result.push_back(sequence.at(index));
        sequence.erase(sequence.begin() + index);
    }
    return result;
}

template<typename T>std::vector<T> RandomChoice::sample(std::vector<T> sequence, std::vector<float> weights, Thread &thread, unsigned int n) {
    try {
        if (sequence.size() != weights.size()) {
            throw RandomChoiceException(sequence.size(), weights.size());
        }

        auto result = std::vector<T>();
        for (unsigned int k = 0; k < n; k++) {
            std::discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
            unsigned int index = distribution(thread.generator);
            result.push_back(sequence.at(index));
            sequence.erase(sequence.begin() + index);
            weights.erase(weights.begin() + index);
        }
        return result;
    } catch (RandomChoiceException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

RandomChoiceException::RandomChoiceException(unsigned long num_elements, unsigned long num_weights) {
    this->num_elements = num_elements;
    this->num_weights = num_weights;
}

const char * RandomChoiceException::what() const noexcept {
    std::string msg = "Number of elements is " + std::to_string(num_elements) + " and weights is " + std::to_string(num_weights) + " but must be equal.";
    return msg.c_str();
}