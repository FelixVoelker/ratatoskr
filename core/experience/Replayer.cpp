#include <iostream>
#include "Replayer.h"

Replayer::Replayer(Session &session) : Singleton(session) {
    network = session.network();
}

void Replayer::replay(Population &pop, vector<Individual *> &old) {
    network->update(pop, old);
    for (Individual *ind : old) {
        delete ind;
    }
}