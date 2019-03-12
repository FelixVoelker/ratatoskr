#ifndef RATATOSKR_THREAD_H
#define RATATOSKR_THREAD_H


#include <random>
#include <thread>

/**
 * Auxilary class to support multi-threading during a session. It stores its own pseudo-random number generator to use
 * for better random choices.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   2.3.2019
 */
class Thread {

public:
    std::mt19937 generator;
    std::thread task;

    explicit Thread();

};

#endif //RATATOSKR_THREAD_H
