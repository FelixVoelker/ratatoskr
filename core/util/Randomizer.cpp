#include <iostream>
#include "Randomizer.h"

Randomizer::Randomizer() {
    random_device device;
    generator = mt19937(device());
}

double Randomizer::random() {
    uniform_real_distribution<float> distribution(0.0, 1.0);
    return distribution(generator);
}

unsigned int Randomizer::randomInt(unsigned int n) {
    uniform_int_distribution<unsigned int> distribution(0, n - 1);
    return distribution(generator);
}

unsigned int Randomizer::randomFromDiscreteDistribution(vector<float> weights) {
    discrete_distribution<unsigned int> distribution(weights.begin(), weights.end());
    return distribution(generator);
}