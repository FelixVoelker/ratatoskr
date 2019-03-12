#include "Session.h"

Session::Session(const EvolutionarySystem &system) : system(system) {}

void Session::run(TerminationCondition &condition) {
    auto *pop = new Population(system.representation, popsize);

    auto *initthreads = new std::vector<Thread>(this->initthreads);
    auto *evalthreads = new std::vector<Thread>(this->evalthreads);
    auto *varythreads = new std::vector<Thread>(this->varythreads);

    system.initialize(*pop, *initthreads);
    /*while (condition.evaluate(pop)) {


    }*/
}

/*Statistics& Session::getStatistics() {
    return statistics;
}*/