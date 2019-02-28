#include "Session.h"

Session::Session(const EvolutionarySystem &system) : system(system) {}

void Session::run(TerminationCondition &condition) {
    Population state(popsize);

    std::vector<Thread> initthreads = buildThreads(this->initthreads);
    std::vector<Thread> evalthreads = buildThreads(this->evalthreads);
    std::vector<Thread> varythreads = buildThreads(this->varythreads);

    while (condition.evaluate(state)) {
        system.evolutionaryCycle(state);
    }
}

Statistics& Session::getStatistics() {
    return statistics;
}

std::vector<Thread> Session::buildThreads(unsigned int n_threads) {
    std::vector<Thread> threads(n_threads);
    unsigned int onset = 0;
    unsigned int offset = popsize / n_threads;
    for (unsigned int k = 0; k < n_threads - 1; k++) {
        threads.at(k) = Thread(k, onset, offset);
        onset += offset;
    }
    threads.at(n_threads - 1) = Thread(n_threads - 1, onset, popsize - onset);
    return threads;
}