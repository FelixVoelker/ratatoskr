#include "Builder.h"

Builder::Builder(Session &session) : Singleton(session) {
    prototype = session.individual();
}

Individual * Builder::build() {
    auto ind = dynamic_cast<Individual *>(prototype->clone());
    initialize(*ind);
    return ind;
}
