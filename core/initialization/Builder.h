#ifndef RATATOSKR_BUILDER_H
#define RATATOSKR_BUILDER_H

#include "../representation/Individual.h"


/**
 * The abstract base class of a population's builder that initializes each individual of an evolutionary system. Rather
 * than initializing the entire population, a builder builds single individuals based of a given prototype.
 * Any Neuro-Dynamic Evolutionary Algorithm (NDEA) has to take this requirement into account.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   2.1.2018
 */
class Builder : public Singleton {

public:
    explicit Builder(Configuration &configuration, Individual *prototype);
    ~Builder();

    /**
     * Builds a new individual by cloning the prototype then initializing it.
     */
    Individual * build() const;

protected:
    Individual *prototype;

    /**
    * Initializes an individual according to the builder's strategy.
    * @param ind The individual to be initialized.
    */
    virtual void initialize(Individual &individual) const = 0;
};


#endif //RATATOSKR_BUILDER_H
