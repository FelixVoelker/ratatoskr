#include <boost/python.hpp>
#include "../../cc/common/Configuration.h"
#include "../../cc/common/FeatureVector.h"
#include "../../cc/common/Problem.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(common) {
    class_<common::Problem, bases<Problem>>("Problem", init<std::function<void(Individual &, Thread &)>, unsigned int, unsigned int>());

    class_<common::Configuration::ProblemConfiguration, bases<Configuration::ProblemConfiguration>>("ProblemConfiguration", init<>())
            .def_readwrite("genes", &common::Configuration::ProblemConfiguration::genes);

    class_<common::Configuration, bases<Configuration>>("Configuration", init<common::Configuration::ProblemConfiguration &>());

    class_<FeatureVector, bases<FeatureMap>>("FeatureVector", init<common::Configuration &>())
            .def("__copy__", &FeatureVector::clone, return_value_policy<manage_new_object>())
            .def("compute", &FeatureVector::compute, return_internal_reference<>());
}