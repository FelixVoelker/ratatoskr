#ifndef RATATOSKR_GENOTYPE_H
#define RATATOSKR_GENOTYPE_H


#include <string>
#include "../util/Clonable.h"

/**
 *
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   12.7.2018
 */
class Genotype : public Clonable {

public:
    bool evaluated = false;

    /**
     * Returns a human-readable representation of the individual.
     */
    virtual std::string toString() = 0;

};


#endif //RATATOSKR_GENOTYPE_H
