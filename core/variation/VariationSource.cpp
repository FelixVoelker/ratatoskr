#include <iostream>
#include "VariationSource.h"

VariationSource::InitializationException::InitializationException(unsigned long sources, unsigned long expected)
        : runtime_error("VariationSource has been given " + to_string(sources)
                        + " sources but expects " + to_string(expected) + ".") {}

VariationSource::VariationSource(const Session &session) : Singleton(session) {}

VariationSource::~VariationSource() {
    for (auto source : sources)
        delete source;
}

void VariationSource::connect(vector<VariationSource *> &sources) {
    try {
        if (sources.size() != expectedSources())
            throw InitializationException(sources.size(), expectedSources());
        else
            this->sources = sources;
    } catch (InitializationException &e) {
        cout << e.what() << endl;
        exit(1);
    }
}

vector<Individual *> VariationSource::vary(const vector<Individual *> &parents, const unsigned int epoch, Randomizer &random) const {
    vector<Individual *> offsprings;
    for (auto source : sources) {
        vector<Individual *> o  = source->vary(parents, epoch, random);
        offsprings.insert(offsprings.end(), o.begin(), o.end());
    }

    if (offsprings.empty())
        offsprings = parents;

    return perform(offsprings, epoch, random);
}
