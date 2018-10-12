#ifndef RATATOSKR_GENOTYPE_H
#define RATATOSKR_GENOTYPE_H


#include <string>
#include "../util/Clonable.h"

/**
 * The abstract base class for any genotype representation of an individual, i.e. a solution in the genotype space.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   1.9.2018
 */
class Genotype : public Clonable {

public:
    bool evaluated = false;

    /**
     * Returns a human-readable representation of the genotype.
     */
    virtual std::string toString() = 0;

};


#endif //RATATOSKR_GENOTYPE_H
