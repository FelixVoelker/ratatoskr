#ifndef RATATOSKR_BREEDINGOPERATORWRAPPER_H
#define RATATOSKR_BREEDINGOPERATORWRAPPER_H


#include <boost/python.hpp>
#include "../../../../core/variation/BreedingOperator.h"

using namespace boost::python;

/**
 * Boost.Python wrapper to expose all virtual core functionality of BreedingOperator.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class BreedingOperatorWrapper : public BreedingOperator, public wrapper<BreedingOperator> {

public:
    explicit BreedingOperatorWrapper(const core::Configuration &configuration);

    unsigned long expectedSources() const override;

    std::vector<Individual *> & breed(std::vector<Individual *> &parents, Thread &thread) const override;

    BreedingOperator * clone() const override;

};


#endif //RATATOSKR_BREEDINGOPERATORWRAPPER_H
