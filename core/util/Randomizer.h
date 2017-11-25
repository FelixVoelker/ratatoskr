#ifndef NDEC_RANDOMIZER_H
#define NDEC_RANDOMIZER_H


#include <random>

using namespace std;

/**
 * TODO: Comments
 * Represents a mersenne twister random generator that produces random integers or numbers according to
 * some given probability distributions.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   8.8.2017
 */
class Randomizer {

private:
    mt19937 generator;

public:
    Randomizer();

    /**
     * Samples a random value from the interval [0.0, 1.0).
     */
    double random();

    /**
     * Samples a random integer from the closed interval [0, n-1] whose values are uniformly distributed.
     * @param n Number of integers within the interval.
     */
    unsigned int randomInt(unsigned int n);

    /**
     * Samples a random integer from the closed interval [0, weights.size()-1] whose values are distributed
     * according to a discrete probability function P(w_i) = w_i / sum.
     * @param weights Set of all weights.
     */
    unsigned int randomFromDiscreteDistribution(vector<float> weights);

};


#endif //NDEC_RANDOMIZER_H
