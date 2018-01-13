#include <boost/python.hpp>
#include "../../cc/common/Configuration.h"
#include "../../cc/common/FeatureVector.h"
#include "../../cc/common/FitnessProportionateSelection.h"
#include "../../cc/common/Problem.h"
#include "../../cc/common/VectorIndividual.h"

using namespace boost::python;

/**
 * Builds the common package of the Python-API.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   13.1.18
 */
BOOST_PYTHON_MODULE(common) {
    class_<common::Problem, bases<core::Problem>>("Problem", init<std::function<void(Individual &, Thread &)>, unsigned int, unsigned int>());

    class_<common::Configuration::ProblemConfiguration, bases<core::Configuration::ProblemConfiguration>>("ProblemConfiguration", init<>())
            .def_readwrite("genes", &common::Configuration::ProblemConfiguration::genes);

    common::Configuration::CrossoverConfiguration& (common::Configuration::*crossover)() = &common::Configuration::getCrossoverConfiguration;
    common::Configuration::MutationConfiguration& (common::Configuration::*mutation)() = &common::Configuration::getMutationConfiguration;

    class_<common::Configuration, bases<core::Configuration>>("Configuration", init<const common::Configuration::ProblemConfiguration &>())
            .add_property("crossover", make_function(crossover, return_internal_reference<>()))
            .add_property("mutation", make_function(mutation, return_internal_reference<>()));

    class_<FeatureVector, bases<FeatureMap>>("FeatureVector", init<const common::Configuration &>())
            .def("__copy__", &FeatureVector::clone, return_value_policy<manage_new_object>())
            .def("compute", &FeatureVector::compute, return_internal_reference<>());

    class_<VectorIndividual, bases<Individual>, boost::noncopyable>("VectorIndividual", init<const common::Configuration &, Cost *, FeatureVector *, Fitness *>())
            .add_property("chromosome", make_function(&VectorIndividual::getChromosome, return_internal_reference<>()))
            .def("__copy__", &VectorIndividual::clone, return_value_policy<manage_new_object>())
            .def("tostring", &VectorIndividual::toString);

    class_<FitnessProportionateSelection, bases<SelectionOperator>>("FitnessProportionateSelection", init<const common::Configuration &>());
}