#ifndef RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H
#define RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H


#include "../../../core/representation/Individual.h"

/**
 * A simple instance of Individual to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   14.12.2017
 */
class SimpleIndividual : public Individual {

public:
    explicit SimpleIndividual(Configuration &configuration, Cost *cost, FeatureMap *featuremap, Fitness *fitness);

    std::string toString() override;

    SimpleIndividual * clone() const override;

    void setLabel(std::string label);

protected:
    SimpleIndividual(const SimpleIndividual &obj);

    std::string label = "";

};


#endif //RATATOSKR_UNIT_SIMPLEINDIVIDUAL_H
