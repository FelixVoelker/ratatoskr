#include <iostream>
#include "Replayer.h"

Replayer::Replayer(const Session &session) : Singleton(session) {
    network = session.network();
}

void Replayer::replay(Population &pop, vector<Individual *> &offsprings) const {
    network->update(pop, offsprings);
}