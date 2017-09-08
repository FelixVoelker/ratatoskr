#ifndef NDEC_BREEDINGOPERATOR_H
#define NDEC_BREEDINGOPERATOR_H

#include "VariationSource.h"

/**
 * The blueprint class for all breeding operators in NDEC. These operators form the internal nodes in the
 * variation pipeline and therefore need to have at least one previous source. In addition to that the root
 * of each pipeline needs to be a breeding operator.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   31.07.2017
 */
class BreedingOperator : public VariationSource {

private:
    /**
     * An exception that is thrown if a breeding operator is not initialized correctly.
     */
    class ZeroSourcesException : public runtime_error {

    public:
        ZeroSourcesException();

    };

protected:
    double prob; // Probability that the operator is performed.

public:
    explicit BreedingOperator(const Session &session);

    void connect(vector<VariationSource *> &sources) override;

    /**
     * Breeds with a certain probability new offsprings from a given set of parents according to
     * the operator's strategy.
     * @param parents Parent individuals for the breeding operation.
     */
    virtual vector<Individual *> & breed(vector<Individual *> &parents, Randomizer &random) const = 0;

    /**
     * Performs the breeding operation on parent individuals and deletes them afterwards.
     */
    vector<Individual *> perform(vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const override;
};


#endif //NDEC_BREEDINGOPERATOR_H
