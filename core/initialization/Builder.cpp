#include "Builder.h"

Builder::Builder(const core::Configuration &configuration, Individual * prototype) : Singleton(configuration) {
    this->prototype = prototype;
}

Builder::~Builder() {
    delete prototype;
}

Individual * Builder::build(Thread &thread) const {
    auto ind = prototype->clone();
    initialize(*ind, thread);
    return ind;
}
