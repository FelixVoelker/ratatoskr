#ifndef RATATOSKR_CORE_TESTVARIATIONSOURCE_H
#define RATATOSKR_CORE_TESTVARIATIONSOURCE_H


#include "../../../core/variation/VariationSource.h"

/**
 * An instance of VariationSource to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestVariationSource : public VariationSource {

protected:
    unsigned long expectedSources() const override;

    vector<Individual *> perform(vector<Individual *> &parents, unsigned int epoch, Randomizer &random) const override;

public:
    explicit TestVariationSource(Session &session);
};


#endif //RATATOSKR_CORE_TESTVARIATIONSOURCE_H
