#ifndef RATATOSKR_SINGLETON_H
#define RATATOSKR_SINGLETON_H


#include "../Session.h"

/**
 * Represents the basic interface for all components of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   11.10.2017
 */
class Singleton {

public:
    /**
     * Initializes a component according to a given session.
     * @param session The session to be run by the evolutionary system.
     */
    explicit Singleton(const Session &session) {};
    virtual ~Singleton() = 0;

};


#endif // RATATOSKR_SINGLETON_H