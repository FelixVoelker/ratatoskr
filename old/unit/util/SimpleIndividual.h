#ifndef RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H
#define RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H


#include "../../core/state/Individual.h"

/**
 * A simple instance of Individual to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleIndividual : public Individual {

public:
    explicit SimpleIndividual(const core::Configuration &configuration, FeatureMap &featuremap, Relevance &relevance);

    std::string toString() override;

    SimpleIndividual * clone() const override;

    void setLabel(std::string label);

protected:
    SimpleIndividual(const SimpleIndividual &obj);

    std::string label = "";

};


#endif //RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H
