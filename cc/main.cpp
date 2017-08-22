#include <iostream>
#include <map>
#include "toolbox/ec/ndga/problem/MaxOne.h"
#include "toolbox/ec/ndga/NDGASession.h"
#include "core/EvolutionarySystem.h"

using namespace std;

int main() {
    auto problem = new MaxOne(200, 50);
    auto session = new NDGASession(*problem);
    session->generations = 200;
    auto system = new EvolutionarySystem(*session);
    system->run();
    delete system;
    delete session;
    delete problem;
    return 0;
}
