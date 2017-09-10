#include <iostream>
#include "problem/ndga/OneMaxProblem.h"
#include "ec/ndga/NDGASession.h"
#include "../core/EvolutionarySystem.h"

int main() {
    auto problem = new OneMaxProblem(50, 5);
    auto session = new NDGASession(*problem);
    session->epochs(1);
    session->episodes(1000);
    session->generations(50);
    session->evalthreads(3);
    session->varythreads(3);
    auto system = new EvolutionarySystem(*session);
    system->run();
    delete system;
    delete session;
    delete problem;
    return 0;
}
