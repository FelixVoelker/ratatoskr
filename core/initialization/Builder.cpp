#include "Builder.h"

Builder::Builder(const Session &session) : Singleton(session) {
    prototype = session.getIndividual();
}

Individual * Builder::build() const {
    auto ind = prototype->clone();
    initialize(*ind);
    return ind;
}
