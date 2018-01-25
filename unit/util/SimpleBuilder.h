#ifndef RATATOSKR_UNIT_SIMPLEBUILDER_H
#define RATATOSKR_UNIT_SIMPLEBUILDER_H


#include "../../core/initialization/Builder.h"

/**
 * A simple instance of Builder to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleBuilder : public Builder {

public:
    explicit SimpleBuilder(const core::Configuration &configuration, Individual *individual);

protected:
    void initialize(Individual &ind, Thread &thread) const override;

};


#endif //RATATOSKR_UNIT_SIMPLEBUILDER_H
