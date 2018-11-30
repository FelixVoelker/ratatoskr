#ifndef RATATOSKR_THREAD_H
#define RATATOSKR_THREAD_H


#include <random>
#include <thread>

/**
 * Represents a thread that processes a specific chunk of the evolutionary system's population. It maintains all
 * information about its corresponding chunk and provides a random module to sample pseudo-random numbers with a
 * mersenne twister random generator. This random module allows to separate its generator from other chunks of the
 * population and therefore prevents that the generator's progression is distorted by other threads.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Thread {

public:
    struct Random {
        std::mt19937 generator = std::mt19937(std::random_device()());

        std::function random = std::bind(std::uniform_real_distribution(0.0, 1.0), generator);

        std::vector<int> choose(int a, int b, std::vector<float> weights = null, unsigned int k = 1);

        /**
         * Chooses k elements of the given sequence with replacement. Selects elements according to its weight or with
         * equal probability if weights is null.
         * @param sequence The list to choose from.
         * @param weights  The weights of each element within the sequence to define a discrete distribution.
         * @param k        Number of elements to choose.
         */
        std::vector<T> choose(std::vector<T> sequence, std::vector<float> weights = null, unsigned int k = 1);

        std::vector<int> sample(int a, int b, std::vector<float> weights = null, unsigned int k = 1);

        /**
         * Samples k elements of the given sequence without replacement. Selects elements according to its weight or with
         * equal probability if weights is null.
         * @param sequence The list to sample from.
         * @param weights  The weights of each element within the sequence to define a discrete distribution.
         * @param k        Number of elements to sample.
         */
        std::vector<T> sample(std::vector<T> sequence, std::vector<float> weights = null, unsigned int k = 1);
    };

    Random random;

    std::thread task;

    /**
     * Creates a thread to process a specific chunk of the population.
     * @param onset  Onset of the thread's corresponding chunk.
     * @param offset Offset of the thread's corresponding chunk.
     */
    explicit Thread(unsigned int id, unsigned int onset, unsigned int offset);

    unsigned int getID() const;
    unsigned int getChunkOnset() const;
    unsigned int getChunkOffset() const;

private:
    unsigned int id;
    unsigned int onset;
    unsigned int offset;

};

#endif //RATATOSKR_THREAD_H
