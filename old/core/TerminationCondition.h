#ifndef RATATOSKR_TERMINATIONCONDITION_H
#define RATATOSKR_TERMINATIONCONDITION_H


#include "../../core/state/Population.h"

/**
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   14.7.2018
 */
class TerminationCondition {

public:
    TerminationCondition();
    TerminationCondition(const TerminationCondition &condition);

    virtual bool evaluate(Population &population) = 0;

protected:
    TerminationCondition *condition;

};


#endif //RATATOSKR_TERMINATIONCONDITION_H
