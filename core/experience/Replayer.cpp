#include <iostream>
#include "Replayer.h"

Replayer::Replayer(const Session &session) : Singleton(session) {
    network = session.network();
}

void Replayer::replay(Population &pop, vector<Individual *> &old) const {
    network->update(pop, old);
}