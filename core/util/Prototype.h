#ifndef RATATOSKR_PROTOTYPE_H
#define RATATOSKR_PROTOTYPE_H


#include "Singleton.h"

/**
 * Represents the basic interface for all components that are defined as prototypes in a session. The evolutionary
 * system derives multiple entities from these prototypes that are to be modified during the evolutionary process.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class Prototype : public Singleton {

public:
    explicit Prototype(const core::Configuration &configuration) : Singleton(configuration) {}

    /**
     * Returns a copy of the calling object.
     */
    virtual Prototype * clone() const = 0;

protected:
    Prototype(const Prototype &obj) = default;

};


#endif //RATATOSKR_PROTOTYPE_H