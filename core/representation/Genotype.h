#ifndef RATATOSKR_GENOTYPE_H
#define RATATOSKR_GENOTYPE_H


#include <string>
#include "../util/Clonable.h"

/**
 * The abstract base class for any point in the search space, i.e. the genotype of an individual to work on.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class Genotype : public Clonable {

public:
    bool evaluated = false;

    virtual ~Genotype() = 0;

    /**
     * Returns a human-readable representation of the genotype.
     */
    virtual std::string toString() = 0;

};


#endif //RATATOSKR_GENOTYPE_H
