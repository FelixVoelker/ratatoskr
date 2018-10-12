#ifndef RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H
#define RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H


#include "../../../core/variation/VariationSource.h"

/**
 * A simple instance of VariationSource to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleVariationSource : public VariationSource {

public:
    explicit SimpleVariationSource(const core::Configuration &configuration);

    SimpleVariationSource * clone() const override;

protected:
    SimpleVariationSource(const SimpleVariationSource &obj) = default;

    unsigned long expectedSources() const override;

    std::vector<Individual *> perform(std::vector<Individual *> &parents, Thread &thread) const override;
};


#endif //RATATOSKR_UNIT_SIMPLEVARIATIONSOURCE_H
