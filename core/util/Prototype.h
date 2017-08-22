#ifndef NDEC_PROTOTYPE_H
#define NDEC_PROTOTYPE_H


#include "Singleton.h"

/**
 * Represents the basic interface for all prototypic components of the evolutionary system, i.e. a singleton
 * with the functionality to create copies from itself.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class Prototype : public Singleton {

protected:
    Prototype(const Prototype &obj);

public:
    /**
     * Initializes the prototype to be cloned from.
     */
    explicit Prototype(Session &session);
    ~Prototype();

    /**
     * Copies a given Prototype object.
     * @return Cloned Prototype object.
     */
    virtual Prototype * clone() = 0;

};


#endif //NDEC_PROTOTYPE_H