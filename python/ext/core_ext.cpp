#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/core/ProblemWrapper.h"
#include "wrapper/core/SessionWrapper.h"
#include "wrapper/core/FeatureMapWrapper.h"
#include "wrapper/core/FitnessWrapper.h"
#include "../../core/EvolutionarySystem.h"
#include "wrapper/core/IndividualWrapper.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(core) {
    class_<std::vector<float>>("std::vector<float>")
            .def(vector_indexing_suite<std::vector<float>>());

    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<boost::shared_ptr<Session>>())
            .def("clone", pure_virtual(&FeatureMap::clone), return_value_policy<manage_new_object>());

    class_<FitnessWrapper, boost::noncopyable>("Fitness", init<boost::shared_ptr<Session>>())
            .def("isideal", pure_virtual(&Fitness::isIdeal))
            .def("operator<", pure_virtual(&Fitness::operator<))
            .def("operator<=", pure_virtual(&Fitness::operator<=))
            .def("operator>", pure_virtual(&Fitness::operator>))
            .def("operator>=", pure_virtual(&Fitness::operator>=))
            .def("operator==", pure_virtual(&Fitness::operator==));

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<boost::shared_ptr<Session>>())
            .add_property("evaluated",
                          static_cast<bool(Individual::*)()>(&Individual::evaluated),
                          static_cast<void(Individual::*)(bool)>(&Individual::evaluated))
            .def("tostring", pure_virtual(&Individual::toString))
            .def("fitness", &Individual::getFitness, return_value_policy<reference_existing_object>())
            .def("featuremap", &Individual::getFeaturemap, return_value_policy<reference_existing_object>())
            .def("clone", pure_virtual(&Individual::clone), return_value_policy<manage_new_object>());

    class_<ProblemWrapper, boost::noncopyable>("Problem", init<unsigned int>())
            .add_property("popsize",
                          static_cast<unsigned int(Problem::*)()>(&Problem::popsize),
                          static_cast<void(Problem::*)(unsigned int)>(&Problem::popsize))
            .def("evaluate", pure_virtual(&Problem::evaluate));

    //TODO: Add pure virtual functions
    class_<SessionWrapper, boost::noncopyable>("Session", init<boost::shared_ptr<Problem>>())
            .add_property("generations",
                          static_cast<unsigned int(Session::*)()>(&Session::generations),
                          static_cast<void(Session::*)(unsigned int)>(&Session::generations))
            .add_property("evalthreads",
                          static_cast<unsigned int(Session::*)()>(&Session::evalthreads),
                          static_cast<void(Session::*)(unsigned int)>(&Session::evalthreads))
            .add_property("varythreads",
                          static_cast<unsigned int(Session::*)()>(&Session::varythreads),
                          static_cast<void(Session::*)(unsigned int)>(&Session::varythreads));
            //.def("builder", &builder);

    class_<Statistics>("Statistics", init<Session &>())
            .add_property("best_fitnesses", &Statistics::bestFitnesses)
            .add_property("average_fitnesses", &Statistics::averageFitnesses)
            .add_property("worst_fitnesses", &Statistics::worstFitnesses);

    class_<EvolutionarySystem>("EvolutionarySystem", init<Session &>())
            .add_property("statistics", &EvolutionarySystem::getStatistics)
            .def("run", &EvolutionarySystem::run);
}