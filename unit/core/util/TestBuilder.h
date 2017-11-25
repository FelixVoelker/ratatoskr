#ifndef RATATOSKR_CORE_TESTBUILDER_H
#define RATATOSKR_CORE_TESTBUILDER_H


#include "../../../core/initialization/Builder.h"

/**
 * An instance of Builder to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestBuilder : public Builder {

protected:
    void initialize(Individual &ind) const override;

public:
    explicit TestBuilder(Session &session);

};


#endif //RATATOSKR_CORE_TESTBUILDER_H
