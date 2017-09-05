#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "../../cc/problem/ndga/OneMaxProblem.h"
#include "../../cc/ec/ndga/BitVectorIndividual.h"
#include "../../cc/ec/ndga/FeatureVector.h"
#include "../../cc/ec/common/RawFitness.h"
#include "wrapper/ndga/ProblemWrapper.h"
#include "../../cc/ec/common/RawRelevance.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(ndga) {
    class_<std::vector<unsigned int>>("std::vector<unsigned int>")
            .def(vector_indexing_suite<std::vector<unsigned int>>());

    class_<FeatureVector, bases<FeatureMap>>("FeatureVector", init<NDGASession &>());

    class_<RawFitness, bases<Fitness>>("RawFitness", init<Session &>())
            .add_property("fitness",
                          static_cast<float(RawFitness::*)()>(&RawFitness::fitness),
                          static_cast<void(RawFitness::*)(float)>(&RawFitness::fitness))
            .add_property("standarized-fitness",
                          static_cast<float(RawFitness::*)()>(&RawFitness::standarizedFitness),
                          static_cast<void(RawFitness::*)(float)>(&RawFitness::standarizedFitness));

    class_<RawRelevance, bases<Relevance>, boost::noncopyable>("RawRelevance", init<Session &>())
            .add_property("cost",
                          static_cast<float(RawRelevance::*)()>(&RawRelevance::cost),
                          static_cast<void(RawRelevance::*)(float)>(&RawRelevance::cost));

    class_<BitVectorIndividual, bases<Individual>, boost::noncopyable>("BitVectorIndividual", init<NDGASession &>())
            .def("chromosome", &BitVectorIndividual::getChromosome, return_value_policy<reference_existing_object>());

    class_<ProblemWrapper, bases<Problem>, boost::noncopyable>("NDGAProblem", init<unsigned int, unsigned int>())
            .add_property("popsize",
                          static_cast<unsigned int(NDGAProblem::*)()>(&NDGAProblem::popsize),
                          static_cast<void(NDGAProblem::*)(unsigned int)>(&NDGAProblem::popsize))
            .def_readwrite("genes", &NDGAProblem::genes)
            .def("evaluate", pure_virtual(&NDGAProblem::evaluate));

    class_<NDGASession, bases<Session>>("NDGASession", init<NDGAProblem &>())
            .def_readwrite("mutationrate", &NDGASession::mutation_rate)
            .def_readwrite("xoverrate", &NDGASession::xover_rate);

    /** Problems **/
    class_<OneMaxProblem, bases<NDGAProblem>>("OneMaxProblem", init<unsigned int, unsigned int>());
}