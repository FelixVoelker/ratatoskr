#include "Builder.h"

Builder::Builder(const core::Configuration &configuration, Individual &prototype) : Prototype(configuration) {
    this->prototype = prototype.clone();
}

Builder::~Builder() {
    delete prototype;
}

Individual * Builder::build(Thread &thread) const {
    auto ind = prototype->clone();
    initialize(*ind, thread);
    return ind;
}

Builder::Builder(const Builder &obj) : Prototype(obj) {
    this->prototype = obj.prototype->clone();
}
