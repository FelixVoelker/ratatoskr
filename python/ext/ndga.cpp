#include <boost/python.hpp>
#include "../../cc/ndga/RandomBitVectorBuilder.h"
#include "../../cc/ndga/BitVectorCrossover.h"
#include "../../cc/ndga/BitVectorMutation.h"
#include "../../cc/ndga/Session.h"
#include "../../cc/ndga/EvaluationFunctions.h"

using namespace boost::python;

/**
 * Builds the ndga package of the Python-API.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
BOOST_PYTHON_MODULE(ndga) {
    class_<RandomBitVectorBuilder, bases<Builder>, boost::noncopyable>("RandomBitVectorIndividual", init<const common::Configuration &, VectorIndividual &>())
            .def("__copy__", &RandomBitVectorBuilder::clone, return_value_policy<manage_new_object>());

    class_<BitVectorCrossover, bases<BreedingOperator>, boost::noncopyable>("BitVectorCrossover", init<const common::Configuration &>())
            .def("__copy__", &BitVectorCrossover::clone, return_value_policy<manage_new_object>());

    class_<BitVectorMutation, bases<BreedingOperator>, boost::noncopyable>("BitVectorMutation", init<const common::Configuration &>())
            .def("__copy__", &BitVectorMutation::clone, return_value_policy<manage_new_object>());

    EvolutionarySystem* (ndga::Session::*build0)() = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build1)(RandomBitVectorBuilder &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build2)(TransitionTable &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build3)(BreedingOperator &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build4)(RandomBitVectorBuilder &, TransitionTable &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build5)(RandomBitVectorBuilder &, BreedingOperator &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build6)(TransitionTable &, BreedingOperator &) = &ndga::Session::build;

    class_<ndga::Session, bases<core::Session>>("Session", init<const common::Problem &>())
            .def(init<const common::Problem &, common::Configuration *>())
            .def("build", build0, return_value_policy<manage_new_object>())
            .def("build", build1, return_value_policy<manage_new_object>())
            .def("build", build2, return_value_policy<manage_new_object>())
            .def("build", build3, return_value_policy<manage_new_object>())
            .def("build", build4, return_value_policy<manage_new_object>())
            .def("build", build5, return_value_policy<manage_new_object>())
            .def("build", build6, return_value_policy<manage_new_object>());

    class_<ndga::EvaluationFunctions>("EvaluationFunctions", init<>())
            .def("one_max", &ndga::EvaluationFunctions::oneMaxEval, return_value_policy<manage_new_object>());
}