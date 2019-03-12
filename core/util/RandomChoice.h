#ifndef RATATOSKR_RANDOMCHOICE_H
#define RATATOSKR_RANDOMCHOICE_H


#include <exception>
#include <functional>
#include <vector>
#include "Thread.h"

/**
 * A helper class for arbitrary random choices that utilizes a thread's mersenne twister random generator.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   2.3.2019
 */
class RandomChoice {

public:
    /**
     * Returns an ordinary random number from the range [0,1].
     * @param thread Current worker thread.
     */
    static float random(Thread &thread);

    /**
     * Chooses n integers from the range [a,b] (or [b,a]) with replacement based on a uniform distribution.
     * @param a       Lower bound of interval.
     * @param b       Upper bound of interval.
     * @param thread  Current worker thread.
     * @param n       Number of elements to choose.
     */
    static std::vector<int> choose(int a, int b, Thread &thread, unsigned int n = 1);

    /**
     * Chooses n elements from the given sequence with replacement based on a uniform distribution.
     * @tparam T       Type of elements.
     * @param sequence Sequence to choose from.
     * @param thread   Current worker thread.
     * @param n        Number of elements to choose.
     */
    template<typename T> static std::vector<T> choose(std::vector<T> sequence, Thread &thread, unsigned int n = 1);

    /**
     * Chooses n elements from the given sequence with replacement based on a discrete distribution.
     * @tparam T       Type of elements.
     * @param sequence Sequence to choose from.
     * @param weights  Weights of the element in the sequence for the discrete distribution.
     * @param thread   Current worker thread.
     * @param n        Number of elements to choose.
     * @throws RandomChoiceException
     */
    template<typename T> static std::vector<T> choose(std::vector<T> sequence, std::vector<float> weights, Thread &thread,  unsigned int n = 1);

    /**
     * Chooses n integers from the range [a,b] (or [b,a]) without replacement based on a uniform distribution.
     * @param a       Lower bound of interval.
     * @param b       Upper bound of interval.
     * @param thread  Current worker thread.
     * @param n       Number of elements to choose.
     */
    static std::vector<int> sample(int a, int b, Thread &thread, unsigned int n = 1);

    /**
     * Chooses n elements from the given sequence without replacement based on a uniform distribution.
     * @tparam T       Type of elements.
     * @param sequence Sequence to choose from.
     * @param thread   Current worker thread.
     * @param n        Number of elements to choose.
     */
    template<typename T> static std::vector<T> sample(std::vector<T> sequence, Thread &thread, unsigned int n = 1);

    /**
     * Chooses n elements from the given sequence without replacement based on a discrete distribution.
     * @tparam T       Type of elements.
     * @param sequence Sequence to choose from.
     * @param weights  Weights of the element in the sequence for the discrete distribution.
     * @param thread   Current worker thread.
     * @param n        Number of elements to choose.
     * @throws RandomChoiceException
     */
    template<typename T> static std::vector<T> sample(std::vector<T> sequence, std::vector<float> weights, Thread &thread,  unsigned int n = 1);

};

/**
 * This exception is used to indicate improper use of RandomChoice.
 */
class RandomChoiceException : public std::exception {

public:
    RandomChoiceException(unsigned long num_elements, unsigned long num_weights);

    const char* what() const noexcept override;

private:
    unsigned long num_elements;
    unsigned long num_weights;
};


#endif //RATATOSKR_RANDOMCHOICE_H
