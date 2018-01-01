#ifndef RATATOSKR_THREAD_H
#define RATATOSKR_THREAD_H


#include <random>
#include "Singleton.h"

/**
 * Represents a thread that processes a specific chunk of the evolutionary system's population. It maintains all
 * information about its corresponding chunk and provides a random module to sample pseudo-random numbers with a
 * mersenne twister random generator. This random module allows to separate its generator from other chunks of the
 * population and therefore prevents that the generator's progression is distorted by other threads.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   29.12.2017
 */
class Thread {

public:
    struct Random {
        std::mt19937 generator = std::mt19937(std::random_device()());

        /**
         * Samples a random number from the interval [0.0, 1.0).
         */
        double sample();

        /**
         * Samples a random integer from the discrete uniform distribution U(0, n-1).
         * @param n Number of discrete values.
         */
        unsigned int sampleIntFromUniformDistribution(unsigned int n);

        /**
         * Samples a random integer from the discrete distribution D(0, n-1) with
         * the probability mass function P(i) = w_i / sum(weights).
         * @param weights Set of all weights w_i.
         */
        unsigned int sampleIntFromDiscreteDistribution(std::vector<float> weights);
    };

    Random random;

    /**
     * Creates a thread to process a specific chunk of the population.
     * @param onset  Onset of the thread's corresponding chunk.
     * @param offset Offset of the thread's corresponding chunk.
     */
    explicit Thread(unsigned int *epoch, unsigned int onset, unsigned int offset);

    unsigned int & getEpoch() const;
    unsigned int getChunkOnset() const;
    unsigned int getChunkOffset() const;

private:
    unsigned int *epoch;
    unsigned int onset;
    unsigned int offset;

};

#endif //RATATOSKR_THREAD_H
