#ifndef RATATOSKR_CORE_TESTINDIVIDUAL_H
#define RATATOSKR_CORE_TESTINDIVIDUAL_H


#include "../../../core/representation/Individual.h"

/**
 * An instance of Individual to test Ratatoskr's core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   9.10.2017
 */
class TestIndividual : public Individual {

public:
    explicit TestIndividual(Session &session);

    string toString() override;

    TestIndividual * clone() const override;

};


#endif //RATATOSKR_CORE_TESTINDIVIDUAL_H
