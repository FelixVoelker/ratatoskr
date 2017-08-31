#include "toolbox/problem/ndga/OneMaxProblem.h"
#include "toolbox/ec/ndga/NDGASession.h"
#include "../core/EvolutionarySystem.h"

int main() {
    auto problem = new OneMaxProblem(200, 50);
    auto session = new NDGASession(*problem);
    /*auto system = new EvolutionarySystem(*session);
    system->run();
    delete system;*/
    delete session;
    delete problem;
    return 0;
}
