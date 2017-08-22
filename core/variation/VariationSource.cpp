#include <iostream>
#include "VariationSource.h"

VariationSource::InitializationException::InitializationException(unsigned long sources, unsigned long expected)
        : runtime_error("VariationSource has been given " + to_string(sources)
                        + " sources but expects " + to_string(expected) + ".") {}

VariationSource::VariationSource(Session &session) : Singleton(session) {}

VariationSource::~VariationSource() {
    for (auto source : sources)
        delete source;
}

void VariationSource::connect(vector<VariationSource *> sources) {
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

vector<Individual *> VariationSource::vary(Population &pop, Randomizer &random) {
    vector<Individual *> parents;
    for (auto &source : sources) {
        vector<Individual *> p  = source->vary(pop, random);
        parents.insert(parents.end(), p.begin(), p.end());
    }

    return perform(pop, parents, random);
}
