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
        if (sources.size() != expectedSources()) {
            std::string error_message = "Number of given sources does not match the expected number.";
            error_message += " Actual: " + std::to_string(this->sources.size());
            error_message += " Expected: " + std::to_string(expectedSources()) + ".";
            throw InitializationException(error_message);
        }

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
            throw InitializationException("Variation Source has not been set up.");

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

VariationSource::InitializationException::InitializationException(std::string error_message)
        : runtime_error(error_message) {}
