#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/BreedingOperatorWrapper.h"
#include "wrapper/BuilderWrapper.h"
#include "wrapper/EvaluationFunctionWrapper.h"
#include "wrapper/FeatureMapWrapper.h"
#include "wrapper/IndividualWrapper.h"
#include "wrapper/RelevanceWrapper.h"
#include "wrapper/SelectionOperatorWrapper.h"
#include "wrapper/VariationSourceWrapper.h"
#include "../../core/Problem.h"
#include "../../../core/statistics/Statistics.h"
#include "../../../../core/old/EvolutionarySystem.h"
#include "../../../../core/old/Session.h"

using namespace boost::python;
using namespace core;

/**
 * Builds the core package of the Python-API.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   26.1.2018
 */
BOOST_PYTHON_MODULE(core) {
    class_<std::vector<float>>("std::genotype<float>")
            .def(vector_indexing_suite<std::vector<float>>());

    class_<std::vector<Individual *>>("std::genotype<Individual>")
            .def(vector_indexing_suite<std::vector<Individual *>>());

    class_<std::vector<VariationSource *>>("std::genotype<VariationSource>")
            .def(vector_indexing_suite<std::vector<VariationSource *>>());

    class_<EvaluationFunctionWrapper, boost::noncopyable>("EvaluationFunction", init<>())
            .def("__copy__", pure_virtual(&EvaluationFunctionWrapper::clone), return_value_policy<manage_new_object>())
            .def("__call__", pure_virtual(&EvaluationFunctionWrapper::operator()));

    class_<BuilderWrapper, boost::noncopyable>("Builder", init<const Configuration &, Individual &>())
            .def("__copy__", pure_virtual(&BuilderWrapper::clone), return_value_policy<manage_new_object>())
            .def("initialize", pure_virtual(&BuilderWrapper::initialize));

    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<const Configuration &>())
            .def("__copy__", pure_virtual(&FeatureMapWrapper::clone), return_value_policy<manage_new_object>());

    class_<RelevanceWrapper, boost::noncopyable>("Relevance", init<const Configuration &>())
            .add_property("cost", &RelevanceWrapper::getCost, &RelevanceWrapper::setCost)
            .add_property("fitness", &RelevanceWrapper::getFitness, &RelevanceWrapper::setFitness)
            .add_property("fraction", &RelevanceWrapper::getFraction, &RelevanceWrapper::setFraction)
            .def("__copy__", &RelevanceWrapper::clone, return_value_policy<manage_new_object>())
            .def("error", &RelevanceWrapper::error)
            .def("isideal", &RelevanceWrapper::isIdeal, &RelevanceWrapper::default_isIdeal)
            .def("relevance", &RelevanceWrapper::relevance)
            .def("adjusted_relevance", &RelevanceWrapper::adjustedRelevance)
            .def("__lt__", &RelevanceWrapper::operator<, &RelevanceWrapper::default_lt)
            .def("__le__", &RelevanceWrapper::operator<=, &RelevanceWrapper::default_leq)
            .def("__gt__", &RelevanceWrapper::operator>, &RelevanceWrapper::default_gt)
            .def("__ge__", &RelevanceWrapper::operator>=, &RelevanceWrapper::default_geq)
            .def("__eq__", &RelevanceWrapper::operator==, &RelevanceWrapper::default_eq)
            .def("__neq__", &RelevanceWrapper::operator!=, &RelevanceWrapper::default_neq);

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<const Configuration &, FeatureMap &, Relevance &>())
            .add_property("evaluated", &IndividualWrapper::isEvaluated, &IndividualWrapper::setEvaluated)
            .def("__copy__", &IndividualWrapper::clone, return_value_policy<manage_new_object>())
            .def("tostring", pure_virtual(&IndividualWrapper::toString))
            .def("getFeaturemap", &IndividualWrapper::getFeaturemap, return_internal_reference<>())
            .def("getRelevance", &IndividualWrapper::getRelevance, return_internal_reference<>());

    class_<Population>("Population", init<const Configuration &>())
            .def("bestIndividual", &Population::bestIndividual, return_internal_reference<>())
            .def("averageIndividual", &Population::averageIndividual, return_internal_reference<>())
            .def("worstIndividual", &Population::worstIndividual, return_internal_reference<>());

    class_<Thread>("Thread", init<unsigned int, unsigned int, unsigned int>())
            .def_readonly("random", &Thread::random)
            .add_property("chunk_onset", &Thread::getChunkOnset)
            .add_property("chunk_offset", &Thread::getChunkOffset);

    class_<Thread::Random>("Random")
            .def("sample", &Thread::Random::sample)
            .def("sampleIntFromUniformDistribution", &Thread::Random::sampleIntFromUniformDistribution)
            .def("sampleIntFromDiscreteDistribution", &Thread::Random::sampleIntFromDiscreteDistribution);

    class_<VariationSourceWrapper, boost::noncopyable>("VariationSource", init<const Configuration &>())
            .def("__copy__", pure_virtual(&VariationSourceWrapper::clone), return_value_policy<manage_new_object>())
            .def("setup", &VariationSourceWrapper::setup)
            .def("expectedSources", pure_virtual(&VariationSourceWrapper::expectedSources))
            .def("perform", pure_virtual(&VariationSourceWrapper::perform));

    class_<SelectionOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("SelectionOperator", init<const Configuration &>())
            .def("__copy__", pure_virtual(&SelectionOperatorWrapper::clone), return_value_policy<manage_new_object>())
            .def("select", pure_virtual(&SelectionOperatorWrapper::select), return_internal_reference<>());

    class_<BreedingOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("BreedingOperator", init<const Configuration &>())
            .def("__copy__", pure_virtual(&BreedingOperatorWrapper::clone), return_value_policy<manage_new_object>())
            .def("expectedSources", pure_virtual(&BreedingOperatorWrapper::expectedSources))
            .def("breed", pure_virtual(&BreedingOperatorWrapper::breed), return_internal_reference<>());

    class_<Statistics>("Statistics", init<const Configuration &>())
            .add_property("epochs", &Statistics::getEpochs)
            .add_property("episodes", &Statistics::getEpisodes)
            .add_property("generations", &Statistics::getGenerations)
            .def("bestCost", &Statistics::bestCost)
            .def("averageCost", &Statistics::averageCost)
            .def("worstCost", &Statistics::worstCost)
            .def("bestFitness", &Statistics::bestFitness)
            .def("averageFitness", &Statistics::averageFitness)
            .def("worstFitness", &Statistics::worstFitness)
            .def("bestRelevance", &Statistics::bestRelevance)
            .def("averageRelevance", &Statistics::averageRelevance)
            .def("worstRelevance", &Statistics::worstRelevance)
            .def("mostRelevantCost", &Statistics::mostRelevantCost)
            .def("leastRelevantCost", &Statistics::leastRelevantCost)
            .def("mostRelevantFitness", &Statistics::mostRelevantFitness)
            .def("leastRelevantFitness", &Statistics::leastRelevantFitness);

    class_<EvolutionarySystem>("EvolutionarySystem", init<const Configuration &, Builder &, EvaluationFunction &, EvolutionaryNetwork &, BreedingOperator &, ReplayMemory &>())
            .add_property("statistics", make_function(&EvolutionarySystem::getStatistics, return_internal_reference<>()))
            .def("run", &EvolutionarySystem::run);

    Configuration::ProblemConfiguration& (Problem::*problem)() = &Problem::getConfiguration;

    class_<Problem>("Problem", init<EvaluationFunction &, unsigned int>())
            .add_property("eval", make_function(&Problem::getEval, return_internal_reference<>()), &Problem::setEval)
            .add_property("configuration", make_function(problem, return_internal_reference<>()));

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

    Configuration::EvolutionarySystemConfiguration& (Configuration::*system)() = &Configuration::getEvolutionarySystemConfiguration;
    Configuration::InitializerConfiguration& (Configuration::*initializer)() = &Configuration::getInitializerConfiguration;
    Configuration::EvaluatorConfiguration& (Configuration::*evaluator)() = &Configuration::getEvaluatorConfiguration;
    Configuration::BreederConfiguration& (Configuration::*breeder)() = &Configuration::getBreederConfiguration;
    Configuration::EvolutionaryNetworkConfiguration& (Configuration::*network)() = &Configuration::getEvolutionaryNetworkConfiguration;

    class_<Configuration>("Configuration", init<const Configuration::ProblemConfiguration &>())
            .add_property("problem", make_function(&Configuration::getProblemConfiguration, return_internal_reference<>()))
            .add_property("system", make_function(system, return_internal_reference<>()))
            .add_property("initializer", make_function(initializer, return_internal_reference<>()))
            .add_property("evaluator", make_function(evaluator, return_internal_reference<>()))
            .add_property("breeder", make_function(breeder, return_internal_reference<>()))
            .add_property("network", make_function(network, return_internal_reference<>()));

    class_<Session>("Session", init<const Problem &>())
            .def(init<const Problem &, Configuration *>())
            .add_property("configuration", make_function(&Session::getConfiguration, return_internal_reference<>()))
            .def("build", &Session::build, return_value_policy<manage_new_object>());
}