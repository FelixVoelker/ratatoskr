#ifndef NDEC_BUILDER_H
#define NDEC_BUILDER_H

#include "../representation/Individual.h"


/**
 * The blueprint class of a population's builder that initializes its individuals. A Builder class is required to
 * build single individuals from a given prototype rather than the entire population. Any subclass has to take
 * this requirement into account in order to fit into the NDEC framework.
 *
 * Furthermore, each Builder object is provided with an instance of the problem at hand. It extracts all
 * relevant problem-dependent data from this Problem object.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   4.8.2017
 */
class Builder : public Singleton {

protected:
    Individual *prototype;

    /**
    * Initializes an individual according to the builder's strategy.
    * @param ind The individual to be initialized.
    */
    virtual void initialize(Individual &ind) const = 0;

public:
    explicit Builder(const Session &session);

    /**
     * Builds a new individual by copying the given prototype then initializing it.
     * @return Pointer to the new individual.
     */
    Individual * build() const;
};


#endif //NDEC_BUILDER_H
