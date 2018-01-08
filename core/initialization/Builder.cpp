#include "Builder.h"

Builder::Builder(Configuration &configuration, Individual * prototype) : Singleton(configuration) {
    this->prototype = prototype;
}

Builder::~Builder() {
    delete prototype;
}

Individual * Builder::build() const {
    auto ind = prototype->clone();
    initialize(*ind);
    return ind;
}
