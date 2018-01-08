#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "../../cc/problem/ndga/OneMaxProblem.h"
#include "../../cc/common/VectorIndividual.h"
#include "../../cc/common/FeatureVector.h"
#include "wrapper/ndga/ProblemWrapper.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(ndga) {
    class_<std::vector<unsigned int>>("std::vector<unsigned int>")
            .def(vector_indexing_suite<std::vector<unsigned int>>());

    /** Tools **/
    class_<FeatureVector, bases<FeatureMap>>("FeatureVector", init<NDGASession &>());

    class_<VectorIndividual, bases<Individual>, boost::noncopyable>("VectorIndividual", init<NDGASession &>())
            .def("chromosome", &VectorIndividual::getChromosome, return_value_policy<reference_existing_object>());

    class_<ProblemWrapper, bases<Problem>, boost::noncopyable>("NDGAProblem", init<unsigned int, unsigned int>())
            .add_property("popsize",
                          static_cast<unsigned int(NDGAProblem::*)()const>(&NDGAProblem::popsize),
                          static_cast<void(NDGAProblem::*)(const unsigned int)>(&NDGAProblem::popsize))
            .def_readwrite("genes", &NDGAProblem::genes)
            .def("evaluate", pure_virtual(&NDGAProblem::evaluate));

    class_<NDGASession, bases<Configuration>>("NDGASession", init<NDGAProblem &>())
            .def_readwrite("mutationrate", &NDGASession::mutation_rate)
            .def_readwrite("xoverrate", &NDGASession::xover_rate);

    /** Problems **/
    class_<OneMaxProblem, bases<NDGAProblem>>("OneMaxProblem", init<unsigned int, unsigned int>());
}