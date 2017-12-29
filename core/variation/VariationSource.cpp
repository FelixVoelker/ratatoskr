#include <iostream>
#include "VariationSource.h"

VariationSource::VariationSource(const Session &session, std::vector<VariationSource *> &sources) : Singleton(session) {
    try {
        if (sources.size() != expectedSources())
            throw InitializationException(sources.size(), expectedSources());
        else {
            this->sources = sources;
        }
    } catch (InitializationException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

VariationSource::~VariationSource() {
    for (auto source : sources)
        delete source;
}

std::vector<Individual *> VariationSource::vary(std::vector<Individual *> &parents, const unsigned int epoch) const {
    std::vector<Individual *> offsprings;
    for (auto source : sources) {
        std::vector<Individual *> breed  = source->vary(parents, epoch);
        offsprings.insert(offsprings.end(), breed.begin(), breed.end());
    }

    if (offsprings.empty())
        offsprings = parents;

    return perform(offsprings, epoch);
}

VariationSource::InitializationException::InitializationException(unsigned long sources, unsigned long expected)
        : runtime_error("VariationSource has been given " + std::to_string(sources)
                        + " sources but expects " + std::to_string(expected) + ".") {}
