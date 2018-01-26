#include <iostream>
#include "VariationSource.h"

VariationSource::VariationSource(const core::Configuration &configuration) : Prototype(configuration) {}

VariationSource::~VariationSource() {
    if (initialized) {
        for (auto *source : *sources)
            delete source;
        std::vector<VariationSource *>().swap(*sources);
        delete sources;
    }
}

void VariationSource::setup(std::vector<VariationSource *> *sources) {
    try {
        if (sources->size() != expectedSources()) {
            std::string error_message = "Number of given sources does not match the expected number.";
            error_message += " Actual: " + std::to_string(this->sources->size());
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

std::vector<Individual *> VariationSource::vary(std::vector<Individual *> &parents, Thread &thread) const {
    try {
        if (!initialized)
            throw InitializationException("Variation Source has not been set up.");

        std::vector<Individual *> offsprings;
        for (auto source : *sources) {
            std::vector<Individual *> breed  = source->vary(parents, thread);
            offsprings.insert(offsprings.end(), breed.begin(), breed.end());
        }

        if (offsprings.empty()) {
            return perform(parents, thread);
        } else {
            return perform(offsprings, thread);
        }
    } catch (InitializationException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

VariationSource::VariationSource(const VariationSource &obj) : Prototype(obj) {
    this->initialized = obj.initialized;
    this->sources = new std::vector<VariationSource *>(obj.sources->size());
    for (unsigned int k = 0; k < sources->size(); k++) {
        this->sources->at(k) = obj.sources->at(k)->clone();
    }
}

VariationSource::InitializationException::InitializationException(std::string error_message)
        : runtime_error(error_message) {}
