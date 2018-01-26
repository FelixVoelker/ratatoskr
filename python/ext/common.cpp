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
 * @version 0.1.0
 * @since   25.1.2018
 */
BOOST_PYTHON_MODULE(common) {
    class_<common::Problem, bases<core::Problem>>("Problem", no_init)
            .def("__init__", make_constructor(+[](boost::python::object eval, unsigned int popsize, unsigned int genes) {
                return new common::Problem(
                        [eval](Individual &individual, Thread &thread) {
                            eval(boost::ref(individual), boost::ref(thread));
                        },
                        popsize,
                        genes);
                })
            );

    class_<common::Configuration::ProblemConfiguration, bases<core::Configuration::ProblemConfiguration>>("ProblemConfiguration", init<>())
            .def_readwrite("genes", &common::Configuration::ProblemConfiguration::genes);

    common::Configuration::CrossoverConfiguration& (common::Configuration::*crossover)() = &common::Configuration::getCrossoverConfiguration;
    common::Configuration::MutationConfiguration& (common::Configuration::*mutation)() = &common::Configuration::getMutationConfiguration;

    class_<common::Configuration, bases<core::Configuration>>("Configuration", init<const common::Configuration::ProblemConfiguration &>())
            .add_property("crossover", make_function(crossover, return_internal_reference<>()))
            .add_property("mutation", make_function(mutation, return_internal_reference<>()));

    class_<FeatureVector, bases<FeatureMap>, boost::noncopyable>("FeatureVector", init<const common::Configuration &>())
            .def("__copy__", &FeatureVector::clone, return_value_policy<manage_new_object>())
            .def("compute", &FeatureVector::compute, return_internal_reference<>());

    class_<VectorIndividual, bases<Individual>, boost::noncopyable>("VectorIndividual", init<const common::Configuration &, FeatureVector &, Relevance &>())
            .add_property("chromosome", make_function(&VectorIndividual::getChromosome, return_internal_reference<>()))
            .def("__copy__", &VectorIndividual::clone, return_value_policy<manage_new_object>())
            .def("tostring", &VectorIndividual::toString);

    class_<FitnessProportionateSelection, bases<SelectionOperator>, boost::noncopyable>("FitnessProportionateSelection", init<const common::Configuration &>())
            .def("__copy__", &FitnessProportionateSelection::clone, return_value_policy<manage_new_object>());
}