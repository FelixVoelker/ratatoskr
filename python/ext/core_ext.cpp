#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/core/BreedingOperatorWrapper.h"
#include "wrapper/core/BuilderWrapper.h"
#include "wrapper/core/CostWrapper.h"
#include "wrapper/core/FeatureMapWrapper.h"
#include "wrapper/core/FitnessWrapper.h"
#include "wrapper/core/IndividualWrapper.h"
#include "wrapper/core/SelectionOperatorWrapper.h"
#include "wrapper/core/VariationSourceWrapper.h"
#include "../../core/evaluation/Problem.h"
#include "../../core/statistics/Statistics.h"
#include "../../core/EvolutionarySystem.h"
#include "../../core/Session.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(core) {
    class_<std::vector<float>>("std::vector<float>")
            .def(vector_indexing_suite<std::vector<float>>());

    class_<std::vector<Individual *>>("std::vector<Individual>")
            .def(vector_indexing_suite<std::vector<Individual *>>());

    class_<std::vector<VariationSource *>>("std::vector<VariationSource>")
            .def(vector_indexing_suite<std::vector<VariationSource *>>());

    class_<BuilderWrapper, boost::noncopyable>("Builder", init<Configuration &, Individual *>())
            .def("initialize", pure_virtual(&BuilderWrapper::initialize));

    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<Configuration &>())
            .def("__copy__", pure_virtual(&FeatureMapWrapper::clone), return_value_policy<manage_new_object>());

    class_<FitnessWrapper, boost::noncopyable>("Fitness", init<Configuration &>())
            .add_property("fitness", &FitnessWrapper::getFitness, &FitnessWrapper::setFitness)
            .def("__copy__", &FitnessWrapper::clone, return_value_policy<manage_new_object>())
            .def("isideal", &FitnessWrapper::isIdeal, &FitnessWrapper::default_isIdeal)
            .def("__lt__", &FitnessWrapper::operator<, &FitnessWrapper::default_lt)
            .def("__le__", &FitnessWrapper::operator<=, &FitnessWrapper::default_leq)
            .def("__gt__", &FitnessWrapper::operator>, &FitnessWrapper::default_gt)
            .def("__ge__", &FitnessWrapper::operator>=, &FitnessWrapper::default_geq)
            .def("__eq__", &FitnessWrapper::operator==, &FitnessWrapper::default_eq)
            .def("__neq__", &FitnessWrapper::operator!=, &FitnessWrapper::default_neq);

    class_<CostWrapper, boost::noncopyable>("Cost", init<Configuration &>())
            .add_property("cost", &CostWrapper::getCost, &CostWrapper::setCost)
            .def("__copy__", &CostWrapper::clone, return_value_policy<manage_new_object>())
            .def("error", &CostWrapper::error)
            .def("__lt__", &CostWrapper::operator<, &CostWrapper::default_lt)
            .def("__le__", &CostWrapper::operator<=, &CostWrapper::default_leq)
            .def("__gt__", &CostWrapper::operator>, &CostWrapper::default_gt)
            .def("__ge__", &CostWrapper::operator>=, &CostWrapper::default_geq)
            .def("__eq__", &CostWrapper::operator==, &CostWrapper::default_eq)
            .def("__neq__", &CostWrapper::operator!=, &CostWrapper::default_neq);

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<Configuration &, Cost *, FeatureMap *, Fitness *>())
            .add_property("evaluated", &IndividualWrapper::isEvaluated, &IndividualWrapper::setEvaluated)
            .def("__copy__", &IndividualWrapper::clone, return_value_policy<manage_new_object>())
            .def("relevance", &IndividualWrapper::relevance)
            .def("tostring", pure_virtual(&IndividualWrapper::toString))
            .def("getCost", &IndividualWrapper::getCost, return_internal_reference<>())
            .def("getFeaturemap", &IndividualWrapper::getFeaturemap, return_internal_reference<>())
            .def("getFitness", &IndividualWrapper::getFitness, return_internal_reference<>());

    class_<Population>("Population", init<Configuration &>())
            .def("bestIndividual", &Population::bestIndividual, return_internal_reference<>())
            .def("averageIndividual", &Population::averageIndividual, return_internal_reference<>())
            .def("worstIndividual", &Population::worstIndividual, return_internal_reference<>());

    class_<Thread>("Thread", init<unsigned int, unsigned int, unsigned int &>())
            .def_readonly("random", &Thread::random)
            .add_property("chunk_onset", &Thread::getChunkOnset)
            .add_property("chunk_offset", &Thread::getChunkOffset)
            .add_property("epoch", &Thread::getEpoch);

    class_<Thread::Random>("Random")
            .def("sample", &Thread::Random::sample)
            .def("sampleIntFromUniformDistribution", &Thread::Random::sampleIntFromUniformDistribution)
            .def("sampleIntFromDiscreteDistribution", &Thread::Random::sampleIntFromDiscreteDistribution);

    class_<VariationSourceWrapper, boost::noncopyable>("VariationSource", init<Configuration &>())
            .def("setup", &VariationSourceWrapper::setup)
            .def("expectedSources", pure_virtual(&VariationSourceWrapper::expectedSources))
            .def("perform", pure_virtual(&VariationSourceWrapper::perform));

    class_<SelectionOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("SelectionOperator", init<Configuration &>())
            .def("select", pure_virtual(&SelectionOperatorWrapper::select), return_internal_reference<>());

    class_<BreedingOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("BreedingOperator", init<Configuration &>())
            .def("expectedSources", pure_virtual(&BreedingOperatorWrapper::expectedSources))
            .def("breed", pure_virtual(&BreedingOperatorWrapper::breed), return_internal_reference<>());

    class_<Statistics>("Statistics", init<Configuration &>())
            .def("bestFitnesses", &Statistics::bestFitnesses)
            .def("averageFitnesses", &Statistics::averageFitnesses)
            .def("worstFitnesses", &Statistics::worstFitnesses);

    class_<EvolutionarySystem>("EvolutionarySystem", init<Configuration &, Builder*, std::function<void(Individual &, Thread &)>&, EvolutionaryNetwork*, BreedingOperator*>())
            .add_property("statistics", make_function(&EvolutionarySystem::getStatistics, return_internal_reference<>()))
            .def("run", &EvolutionarySystem::run);

    class_<Problem>("Problem", init<std::function<void(Individual &, Thread &)>, unsigned int>())
            .add_property("eval", make_function(&Problem::getEval, return_internal_reference<>()), &Problem::setEval)
            .add_property("configuration", make_function(&Problem::getConfiguration, return_internal_reference<>()));

    class_<Configuration::ProblemConfiguration>("ProblemConfiguration", init<>())
            .def_readwrite("popsize", &Configuration::ProblemConfiguration::popsize);

    class_<Configuration::EvolutionarySystemConfiguration>("EvolutionarySystemConfiguration", init<>())
            .def_readwrite("complete", &Configuration::EvolutionarySystemConfiguration::complete)
            .def_readwrite("epochs", &Configuration::EvolutionarySystemConfiguration::epochs)
            .def_readwrite("episodes", &Configuration::EvolutionarySystemConfiguration::episodes)
            .def_readwrite("generations", &Configuration::EvolutionarySystemConfiguration::generations);

    class_<Configuration::InitializerConfiguration>("InitializerConfiguration", init<>())
            .def_readwrite("threads", &Configuration::InitializerConfiguration::threads);

    class_<Configuration::EvaluatorConfiguration>("EvaluatorConfiguration", init<>())
            .def_readwrite("threads", &Configuration::EvaluatorConfiguration::threads);

    class_<Configuration::BreederConfiguration>("BreederConfiguration", init<>())
            .def_readwrite("threads", &Configuration::BreederConfiguration::threads);

    class_<Configuration::EvolutionaryNetworkConfiguration>("EvolutionaryNetworkConfiguration", init<>())
            .def_readwrite("discount_factor", &Configuration::EvolutionaryNetworkConfiguration::discount_factor)
            .def_readwrite("learning_rate", &Configuration::EvolutionaryNetworkConfiguration::learning_rate);

    class_<Configuration>("Configuration", init<Configuration::ProblemConfiguration &>())
            .add_property("problem", make_function(&Configuration::getProblemConfiguration, return_internal_reference<>()))
            .add_property("system", make_function(&Configuration::getEvolutionarySystemConfiguration, return_internal_reference<>()))
            .add_property("initializer", make_function(&Configuration::getInitializerConfiguration, return_internal_reference<>()))
            .add_property("evaluator", make_function(&Configuration::getEvaluatorConfiguration, return_internal_reference<>()))
            .add_property("breeder", make_function(&Configuration::getBreederConfiguration, return_internal_reference<>()))
            .add_property("network", make_function(&Configuration::getEvolutionaryNetworkConfiguration, return_internal_reference<>()));

    class_<Session>("Session", init<Problem &>())
            .def(init<Problem &, Configuration *>())
            .add_property("configuration", make_function(&Session::getConfiguration, return_internal_reference<>()))
            .def("build", &Session::build, return_value_policy<manage_new_object>());
}