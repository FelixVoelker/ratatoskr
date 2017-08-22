#ifndef NDEC_SINGLETON_H
#define NDEC_SINGLETON_H


#include <string>
#include "../Session.h"

using namespace std;

/**
 * Represents the basic interface for all components of the evolutionary system.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class Singleton {

protected:
    Singleton(const Singleton &obj);

public:
    /**
     * Initializes a component according to the given Session.
     */
    explicit Singleton(Session &session);

};


#endif //NDEC_SINGLETON_H