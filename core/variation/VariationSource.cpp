#include <iostream>
#include "VariationSource.h"

VariationSource::VariationSource(const Session &session) : Singleton(session) {}

VariationSource::~VariationSource() {
    if (initialized) {
        for (auto source : sources)
            delete source;
    }
}

void VariationSource::setup(std::vector<VariationSource *> &sources) {
    try {
        if (sources.size() != expectedSources())
            throw InitializationException(sources.size(), expectedSources());

        this->sources = sources;
        initialized = true;
    } catch (InitializationException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

std::vector<Individual *> VariationSource::vary(std::vector<Individual *> &parents, const unsigned int epoch, Thread &thread) const {
    try {
        if (!initialized)
            throw InitializationException();

        std::vector<Individual *> offsprings;
        for (auto source : sources) {
            std::vector<Individual *> breed  = source->vary(parents, epoch, thread);
            offsprings.insert(offsprings.end(), breed.begin(), breed.end());
        }

        if (offsprings.empty()) {
            return perform(parents, epoch, thread);
        } else {
            return perform(offsprings, epoch, thread);
        }
    } catch (InitializationException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

VariationSource::InitializationException::InitializationException()
        : runtime_error("Variation Source has not been initialized.") {}

VariationSource::InitializationException::InitializationException(unsigned long sources, unsigned long expected)
        : runtime_error("Number of given sources does not match the expected number. Actual: " + std::to_string(sources)
                        + ", Expected: " + std::to_string(expected) + ".") {}
