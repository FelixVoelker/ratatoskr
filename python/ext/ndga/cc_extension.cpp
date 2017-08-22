#include <boost/python.hpp>
#include "../../../cc/toolbox/ec/common/FitnessProportionateSelection.h"
#include "../../../cc/toolbox/ec/common/RawFitness.h"
#include "../../../cc/toolbox/ec/ndga/BitVectorCrossover.h"
#include "../../../cc/toolbox/ec/ndga/BitVectorMutation.h"
#include "../../../cc/toolbox/ec/ndga/BitVectorIndividual.h"
#include "../../../cc/toolbox/ec/ndga/FeatureVector.h"
#include "../../../cc/toolbox/ec/ndga/NDGAProblem.h"
#include "../../../cc/toolbox/ec/ndga/NDGASession.h"
#include "../../../cc/toolbox/ec/ndga/RandomBitVectorBuilder.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(common) {
    /*class_<FitnessProportionateSelection, bases<SelectionOperator>>("FitnessProportionateSelection", init<Session>());
    class_<RawFitness, bases<Fitness>>("RawFitness", init<Session>());*/
}

BOOST_PYTHON_MODULE(ndga) {
    /*import("common");
    class_<BitVectorCrossover, bases<BreedingOperator>>("BitVectorCrossover", init<Session>());
    class_<BitVectorMutation, bases<BreedingOperator>>("BitVectorMutation", init<Session>());
    class_<BitVectorIndividual, bases<Individual>>("BitVectorIndividual", init<Session>());
    class_<FeatureVector, bases<FeatureMap>>("FeatureVector", init<Session>());
    class_<NDGAProblem, bases<Problem>>("NDGAProblem", init<unsigned int, unsigned int>());
            //.def_readwrite("genes", &NDGAProblem::genes);
    class_<NDGASession, bases<Session>>("NDGASession", init<NDGAProblem>())
            .def_readwrite("xoverrate", &NDGASession::xover_rate)
            .def_readwrite("mutationrate", &NDGASession::mutation_rate);
    class_<RandomBitVectorBuilder, bases<Builder>>("RandomBitVectorBuilder");*/
}