#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/core/ProblemWrapper.h"
#include "wrapper/core/SessionWrapper.h"
#include "wrapper/core/FeatureMapWrapper.h"
#include "wrapper/core/FitnessWrapper.h"
#include "../../core/EvolutionarySystem.h"
#include "wrapper/core/IndividualWrapper.h"
#include "wrapper/core/RelevanceWrapper.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(core) {
    class_<std::vector<float>>("std::vector<float>")
            .def(vector_indexing_suite<std::vector<float>>());
    class_<std::vector<vector<float>>>("std::vector<std::vector<float>>")
            .def(vector_indexing_suite<std::vector<std::vector<float>>>());

    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<boost::shared_ptr<Session>>())
            .def("clone", pure_virtual(&FeatureMap::clone), return_value_policy<manage_new_object>());

    class_<FitnessWrapper, boost::noncopyable>("Fitness", init<boost::shared_ptr<Session>>())
            .def("isideal", pure_virtual(&Fitness::isIdeal))
            .def("operator<", pure_virtual(&Fitness::operator<))
            .def("operator<=", pure_virtual(&Fitness::operator<=))
            .def("operator>", pure_virtual(&Fitness::operator>))
            .def("operator>=", pure_virtual(&Fitness::operator>=))
            .def("operator==", pure_virtual(&Fitness::operator==));

    class_<RelevanceWrapper, boost::noncopyable>("Relevance", init<boost::shared_ptr<Session>>())
            .def("relevance", pure_virtual(&Relevance::relevance))
            .def("fitness", &Relevance::getFitness, return_value_policy<reference_existing_object>())
            .def("clone", pure_virtual(&Relevance::clone), return_value_policy<manage_new_object>());;

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<boost::shared_ptr<Session>>())
            .add_property("evaluated",
                          static_cast<bool(Individual::*)()const>(&Individual::evaluated),
                          static_cast<void(Individual::*)(const bool)>(&Individual::evaluated))
            .def("tostring", pure_virtual(&Individual::toString))
            .def("relevance", &Individual::getRelevance, return_value_policy<reference_existing_object>())
            .def("featuremap", &Individual::getFeaturemap, return_value_policy<reference_existing_object>())
            .def("clone", pure_virtual(&Individual::clone), return_value_policy<manage_new_object>());

    class_<ProblemWrapper, boost::noncopyable>("Problem", init<unsigned int>())
            .add_property("popsize",
                          static_cast<unsigned int(Problem::*)()const>(&Problem::popsize),
                          static_cast<void(Problem::*)(const unsigned int)>(&Problem::popsize))
            .def("evaluate", pure_virtual(&Problem::evaluate));

    //TODO: Add pure virtual functions
    class_<SessionWrapper, boost::noncopyable>("Session", init<boost::shared_ptr<Problem>>())
            .add_property("epochs",
                          static_cast<unsigned int(Session::*)()const>(&Session::epochs),
                          static_cast<void(Session::*)(unsigned int)>(&Session::epochs))
            .add_property("episodes",
                          static_cast<unsigned int(Session::*)()const>(&Session::episodes),
                          static_cast<void(Session::*)(unsigned int)>(&Session::episodes))
            .add_property("generations",
                          static_cast<unsigned int(Session::*)()const>(&Session::generations),
                          static_cast<void(Session::*)(unsigned int)>(&Session::generations))
            .add_property("complete",
                          static_cast<bool(Session::*)()const>(&Session::complete),
                          static_cast<void(Session::*)(bool)>(&Session::complete))
            .add_property("evalthreads",
                          static_cast<unsigned int(Session::*)()const>(&Session::evalthreads),
                          static_cast<void(Session::*)(unsigned int)>(&Session::evalthreads))
            .add_property("varythreads",
                          static_cast<unsigned int(Session::*)()const>(&Session::varythreads),
                          static_cast<void(Session::*)(unsigned int)>(&Session::varythreads))
            .add_property("learningrate",
                          static_cast<float(Session::*)()const>(&Session::learning_rate),
                          static_cast<void(Session::*)(float)>(&Session::learning_rate))
            .add_property("discount-factor",
                          static_cast<float(Session::*)()const>(&Session::discount_factor),
                          static_cast<void(Session::*)(float)>(&Session::discount_factor));
            //.def("builder", &builder);

    class_<Statistics>("Statistics", init<Session &>())
            .def("bestFitnesses", static_cast<vector<vector<float>>(Statistics::*)()const>(&Statistics::bestFitnesses))
            .def("averageFitnesses", static_cast<vector<vector<float>>(Statistics::*)()const>(&Statistics::averageFitnesses))
            .def("worstFitnesses", static_cast<vector<vector<float>>(Statistics::*)()const>(&Statistics::worstFitnesses))
            .def("bestFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::bestFitnesses))
            .def("averageFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::averageFitnesses))
            .def("worstFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::worstFitnesses));

    class_<EvolutionarySystem>("EvolutionarySystem", init<Session &>())
            .add_property("statistics", &EvolutionarySystem::getStatistics)
            .def("run", &EvolutionarySystem::run);
}