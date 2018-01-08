#include <boost/python.hpp>
#include "../../cc/common/Configuration.h"
#include "../../cc/common/Problem.h"

using namespace boost::python;
using namespace common;

BOOST_PYTHON_MODULE(common) {
    class_<Problem, bases<core::Problem>>("Problem", init<std::function<void(Individual &, Thread &)>, unsigned int, unsigned int>());

    class_<Configuration::ProblemConfiguration,
            bases<core::Configuration::ProblemConfiguration>>("ProblemConfiguration", init<>())
            .def_readwrite("genes", &Configuration::ProblemConfiguration::genes);

    class_<Configuration, bases<core::Configuration>>("Configuration", init<Configuration::ProblemConfiguration &>());
}