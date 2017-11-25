#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/core/TaskWrapper.h"
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

    class_<TaskWrapper, boost::noncopyable>("Problem", init<unsigned int>())
            .add_property("popsize", &Problem::getPopsize, &Problem::setPopsize)
            .def("eval", pure_virtual(&Problem::eval))
            .def("clone", pure_virtual(&Problem::clone));

    // Workspace
    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<boost::shared_ptr<Session>>())
            .def("clone", pure_virtual(&FeatureMap::clone), return_value_policy<manage_new_object>());

    class_<FitnessWrapper, boost::noncopyable>("Fitness", init<boost::shared_ptr<Session>>())
            .add_property("fitness",
                          static_cast<float(Fitness::*)()const>(&Fitness::fitness),
                          static_cast<void(Fitness::*)(const float)>(&Fitness::fitness))
            .def("isideal", &Fitness::isIdeal, &FitnessWrapper::default_isIdeal)
            .def("operator<", &Fitness::operator<, &FitnessWrapper::default_lt)
            .def("operator<=", &Fitness::operator<=, &FitnessWrapper::default_leq)
            .def("operator>", &Fitness::operator>, &FitnessWrapper::default_gt)
            .def("operator>=", &Fitness::operator>=, &FitnessWrapper::default_geq)
            .def("operator==", &Fitness::operator==, &FitnessWrapper::default_eq);

    class_<RelevanceWrapper, boost::noncopyable>("Relevance", init<boost::shared_ptr<Session>>())
            .add_property("cost",
                          static_cast<float(Relevance::*)()const>(&Relevance::cost),
                          static_cast<void(Relevance::*)(const float)>(&Relevance::cost))
            .def("relevance", &Relevance::relevance, &RelevanceWrapper::default_relevance)
            .def("fitness", &Relevance::getFitness, return_value_policy<reference_existing_object>());

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<boost::shared_ptr<Session>>())
            .add_property("evaluated",
                          static_cast<bool(Individual::*)()const>(&Individual::evaluated),
                          static_cast<void(Individual::*)(const bool)>(&Individual::evaluated))
            .def("tostring", pure_virtual(&Individual::toString))
            .def("relevance", &Individual::getRelevance, return_value_policy<reference_existing_object>())
            .def("featuremap", &Individual::getFeaturemap, return_value_policy<reference_existing_object>());

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
                          static_cast<void(Session::*)(float)>(&Session::discount_factor))
            .def("network", pure_virtual(static_cast<void(Session::*)(EvolutionaryNetwork&)>(&Session::network)))
            .def("builder", pure_virtual(static_cast<void(Session::*)(Builder&)>(&Session::builder)))
            .def("fitness", pure_virtual(static_cast<void(Session::*)(Fitness&)>(&Session::fitness)))
            .def("relevance", pure_virtual(static_cast<void(Session::*)(Relevance&)>(&Session::relevance)))
            .def("featuremap", pure_virtual(static_cast<void(Session::*)(FeatureMap&)>(&Session::featuremap)))
            .def("individual", pure_virtual(static_cast<void(Session::*)(Individual&)>(&Session::individual)))
            .def("pipeline", pure_virtual(static_cast<void(Session::*)(BreedingOperator&)>(&Session::pipeline)));

    class_<Statistics>("Statistics", init<Session &>())
            .def("bestFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::bestFitnesses))
            .def("averageFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::averageFitnesses))
            .def("worstFitnesses", static_cast<vector<float>(Statistics::*)(unsigned int)const>(&Statistics::worstFitnesses));

    class_<EvolutionarySystem>("EvolutionarySystem", init<Session &>())
            .add_property("statistics", &EvolutionarySystem::getStatistics)
            .def("run", &EvolutionarySystem::run);
}