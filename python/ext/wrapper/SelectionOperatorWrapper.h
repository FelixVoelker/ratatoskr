#ifndef RATATOSKR_SELECTIONOPERATORWRAPPER_H
#define RATATOSKR_SELECTIONOPERATORWRAPPER_H


#include <boost/python.hpp>
#include "../../../core/variation/SelectionOperator.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of SelectionOperator.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   19.1.2018
 */
class SelectionOperatorWrapper : public SelectionOperator, public wrapper<SelectionOperator> {

public:
    explicit SelectionOperatorWrapper(const core::Configuration &configuration);

    Individual * select(std::vector<Individual *> &parents, Thread &thread) const override;
};


#endif //RATATOSKR_SELECTIONOPERATORWRAPPER_H
