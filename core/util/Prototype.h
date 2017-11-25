#ifndef RATATOSKR_PROTOTYPE_H
#define RATATOSKR_PROTOTYPE_H


#include "Singleton.h"
#include "Clonable.h"

/**
 * Represents the basic interface for all components that are defined as prototypes in a session. The evolutionary
 * system derives multiple entities from these prototypes that are to be modified during the evolutionary process.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   11.10.2017
 */
class Prototype : public Singleton, public Clonable {

public:
    explicit Prototype(const Session &session) : Singleton(session) {};

};


#endif //RATATOSKR_PROTOTYPE_H