#ifndef RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H
#define RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H


#include "../../../core/variation/VariationSource.h"

/**
 * A simple instance of VariationSource to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   30.12.2017
 */
class SimpleVariationSource : public VariationSource {

public:
    explicit SimpleVariationSource(Session &session);

protected:
    unsigned long expectedSources() const override;

    std::vector<Individual *> perform(std::vector<Individual *> &parents, unsigned int epoch, Thread &thread) const override;
};


#endif //RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H
