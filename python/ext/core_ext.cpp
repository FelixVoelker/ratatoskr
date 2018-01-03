#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "wrapper/core/BreedingOperatorWrapper.h"
#include "wrapper/core/BuilderWrapper.h"
#include "wrapper/core/CostWrapper.h"
#include "wrapper/core/FeatureMapWrapper.h"
#include "wrapper/core/FitnessWrapper.h"
#include "wrapper/core/IndividualWrapper.h"
#include "wrapper/core/ProblemWrapper.h"
#include "wrapper/core/SelectionOperatorWrapper.h"
#include "wrapper/core/SessionWrapper.h"
#include "wrapper/core/VariationSourceWrapper.h"
#include "../../core/representation/Population.h"
#include "../../core/statistics/Statistics.h"
#include "../../core/util/Thread.h"
#include "../../core/EvolutionarySystem.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(core) {
    class_<std::vector<float>>("std::vector<float>")
            .def(vector_indexing_suite<std::vector<float>>());

    class_<std::vector<Individual *>>("std::vector<Individual>")
            .def(vector_indexing_suite<std::vector<Individual *>>());

    class_<std::vector<VariationSource *>>("std::vector<VariationSource>")
            .def(vector_indexing_suite<std::vector<VariationSource *>>());

    class_<BuilderWrapper, boost::noncopyable>("Builder", init<boost::shared_ptr<SessionWrapper>>())
            .def("initialize", pure_virtual(&BuilderWrapper::initialize));

    class_<FeatureMapWrapper, boost::noncopyable>("FeatureMap", init<boost::shared_ptr<SessionWrapper>>())
            .def("__copy__", pure_virtual(&FeatureMapWrapper::clone), return_value_policy<manage_new_object>());

    class_<FitnessWrapper, boost::noncopyable>("Fitness", init<boost::shared_ptr<SessionWrapper>>())
            .add_property("fitness", &FitnessWrapper::getFitness, &FitnessWrapper::setFitness)
            .def("__copy__", &FitnessWrapper::clone, return_value_policy<manage_new_object>())
            .def("isideal", &FitnessWrapper::isIdeal, &FitnessWrapper::default_isIdeal)
            .def("__lt__", &FitnessWrapper::operator<, &FitnessWrapper::default_lt)
            .def("__le__", &FitnessWrapper::operator<=, &FitnessWrapper::default_leq)
            .def("__gt__", &FitnessWrapper::operator>, &FitnessWrapper::default_gt)
            .def("__ge__", &FitnessWrapper::operator>=, &FitnessWrapper::default_geq)
            .def("__eq__", &FitnessWrapper::operator==, &FitnessWrapper::default_eq)
            .def("__neq__", &FitnessWrapper::operator!=, &FitnessWrapper::default_neq);

    class_<CostWrapper, boost::noncopyable>("Cost", init<boost::shared_ptr<SessionWrapper>>())
            .add_property("cost", &CostWrapper::getCost, &CostWrapper::setCost)
            .def("__copy__", &CostWrapper::clone, return_value_policy<manage_new_object>())
            .def("error", &CostWrapper::error)
            .def("__lt__", &CostWrapper::operator<, &CostWrapper::default_lt)
            .def("__le__", &CostWrapper::operator<=, &CostWrapper::default_leq)
            .def("__gt__", &CostWrapper::operator>, &CostWrapper::default_gt)
            .def("__ge__", &CostWrapper::operator>=, &CostWrapper::default_geq)
            .def("__eq__", &CostWrapper::operator==, &CostWrapper::default_eq)
            .def("__neq__", &CostWrapper::operator!=, &CostWrapper::default_neq);

    class_<IndividualWrapper, boost::noncopyable>("Individual", init<boost::shared_ptr<SessionWrapper>>())
            .add_property("evaluated", &IndividualWrapper::isEvaluated, &IndividualWrapper::setEvaluated)
            .def("__copy__", &IndividualWrapper::clone, return_value_policy<manage_new_object>())
            .def("relevance", &IndividualWrapper::relevance)
            .def("tostring", pure_virtual(&IndividualWrapper::toString))
            .def("getCost", &IndividualWrapper::getCost, return_internal_reference<>())
            .def("getFeaturemap", &IndividualWrapper::getFeaturemap, return_internal_reference<>())
            .def("getFitness", &IndividualWrapper::getFitness, return_internal_reference<>());

    class_<Population>("Population", init<Session &>())
            .def("bestIndividual", &Population::bestIndividual, return_internal_reference<>())
            .def("averageIndividual", &Population::averageIndividual, return_internal_reference<>())
            .def("worstIndividual", &Population::worstIndividual, return_internal_reference<>());

    class_<Thread>("Thread", init<unsigned int, unsigned int, unsigned int&>())
            .def_readonly("random", &Thread::random)
            .add_property("chunk_onset", &Thread::getChunkOnset)
            .add_property("chunk_offset", &Thread::getChunkOffset)
            .add_property("epoch", &Thread::getEpoch);

    class_<Thread::Random>("Random")
            .def("sample", &Thread::Random::sample)
            .def("sampleIntFromUniformDistribution", &Thread::Random::sampleIntFromUniformDistribution)
            .def("sampleIntFromDiscreteDistribution", &Thread::Random::sampleIntFromDiscreteDistribution);

    class_<VariationSourceWrapper, boost::noncopyable>("VariationSource", init<boost::shared_ptr<SessionWrapper>>())
            .def("setup", &VariationSourceWrapper::setup)
            .def("expectedSources", pure_virtual(&VariationSourceWrapper::expectedSources))
            .def("perform", pure_virtual(&VariationSourceWrapper::perform));

    class_<SelectionOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("SelectionOperator", init<boost::shared_ptr<SessionWrapper>>())
            .def("select", pure_virtual(&SelectionOperatorWrapper::select), return_internal_reference<>());

    class_<BreedingOperatorWrapper, bases<VariationSourceWrapper>, boost::noncopyable>("BreedingOperator", init<boost::shared_ptr<SessionWrapper>>())
            .def("expectedSources", pure_virtual(&BreedingOperatorWrapper::expectedSources))
            .def("breed", pure_virtual(&BreedingOperatorWrapper::breed), return_internal_reference<>());

    class_<ProblemWrapper, boost::noncopyable>("Problem", init<unsigned int>())
            .add_property("popsize", &ProblemWrapper::getPopsize, &ProblemWrapper::setPopsize)
            .def("eval", pure_virtual(&ProblemWrapper::eval));

    class_<SessionWrapper, boost::noncopyable>("Session", init<boost::shared_ptr<ProblemWrapper>>())
            .add_property("epochs", &SessionWrapper::getEpochs, &SessionWrapper::setEpochs)
            .add_property("episodes", &SessionWrapper::getEpisodes, &SessionWrapper::setEpisodes)
            .add_property("generations", &SessionWrapper::getGenerations, &SessionWrapper::setGenerations)
            .add_property("complete", &SessionWrapper::isComplete, &SessionWrapper::setComplete)
            .add_property("evalthreads", &SessionWrapper::getEvalthreads, &SessionWrapper::setEvalthreads)
            .add_property("varythreads", &SessionWrapper::getVarythreads, &SessionWrapper::setVarythreads)
            .add_property("learning_rate", &SessionWrapper::getLearningRate, &SessionWrapper::setLearningRate)
            .add_property("discount_factor", &SessionWrapper::getDiscountFactor, &SessionWrapper::setDiscountFactor)
            .add_property("builder", make_function(&SessionWrapper::getBuilder, return_internal_reference<>()), &SessionWrapper::pyBuilder)
            .add_property("cost", make_function(&SessionWrapper::getCost, return_internal_reference<>()), &SessionWrapper::pyCost)
            .add_property("featuremap", make_function(&SessionWrapper::getFeaturemap, return_internal_reference<>()), &SessionWrapper::pyFeaturemap)
            .add_property("fitness", make_function(&SessionWrapper::getFitness, return_internal_reference<>()), &SessionWrapper::pyFitness)
            .add_property("individual", make_function(&SessionWrapper::getIndividual, return_internal_reference<>()), &SessionWrapper::pyIndividual)
            .def("builder", pure_virtual(&SessionWrapper::setBuilder))
            .def("cost", pure_virtual(&SessionWrapper::setCost))
            .def("featuremap", pure_virtual(&SessionWrapper::setFeaturemap))
            .def("fitness", pure_virtual(&SessionWrapper::setFitness))
            .def("individual", pure_virtual(&SessionWrapper::setIndividual));

    class_<Statistics>("Statistics", init<Session &>())
            .def("bestFitnesses", &Statistics::bestFitnesses)
            .def("averageFitnesses", &Statistics::averageFitnesses)
            .def("worstFitnesses", &Statistics::worstFitnesses);

    class_<EvolutionarySystem>("EvolutionarySystem", init<Session &>())
            .add_property("statistics", make_function(&EvolutionarySystem::getStatistics, return_internal_reference<>()))
            .def("run", &EvolutionarySystem::run);
}