#include "Builder.h"

Builder::Builder(const Session &session) : Singleton(session) {
    prototype = session.individual();
}

Individual * Builder::build() const {
    auto ind = dynamic_cast<Individual *>(prototype->clone());
    initialize(*ind);
    return ind;
}
