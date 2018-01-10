#include <boost/python.hpp>
#include "../../cc/ndga/RandomBitVectorBuilder.h"
#include "../../cc/ndga/BitVectorCrossover.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(ndga) {
    class_<RandomBitVectorBuilder, bases<Builder>>("RandomBitVectorIndividual", init<common::Configuration &, VectorIndividual *>());

    class_<BitVectorCrossover, bases<BreedingOperator>>("BitVectorCrossover", init<common::Configuration &>());

//    class_<NDGASession, bases<Configuration>>("NDGASession", init<NDGAProblem &>())
//            .def_readwrite("mutationrate", &NDGASession::mutation_rate)
//            .def_readwrite("xoverrate", &NDGASession::xover_rate);
//
//    /** Problems **/
//    class_<OneMaxProblem, bases<NDGAProblem>>("OneMaxProblem", init<unsigned int, unsigned int>());
}