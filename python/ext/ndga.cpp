#include <boost/python.hpp>
#include "../../cc/representation/vector/binary/RandomBinaryVectorBuilder.h"
#include "../../cc/representation/vector/binary/BinaryVectorCrossover.h"
#include "../../cc/representation/vector/binary/BinaryVectorMutation.h"
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
    class_<RandomBinaryVectorBuilder, bases<Builder>, boost::noncopyable>("RandomBitVectorIndividual", init<const common::Configuration &, VectorIndividual &>())
            .def("__copy__", &RandomBinaryVectorBuilder::clone, return_value_policy<manage_new_object>());

    class_<BinaryVectorCrossover, bases<BreedingOperator>, boost::noncopyable>("BitVectorCrossover", init<const common::Configuration &>())
            .def("__copy__", &BinaryVectorCrossover::clone, return_value_policy<manage_new_object>());

    class_<BinaryVectorMutation, bases<BreedingOperator>, boost::noncopyable>("BitVectorMutation", init<const common::Configuration &>())
            .def("__copy__", &BinaryVectorMutation::clone, return_value_policy<manage_new_object>());

    EvolutionarySystem* (ndga::Session::*build0)() = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build1)(RandomBinaryVectorBuilder &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build2)(TransitionTable &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build3)(BreedingOperator &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build4)(RandomBinaryVectorBuilder &, TransitionTable &) = &ndga::Session::build;
    EvolutionarySystem* (ndga::Session::*build5)(RandomBinaryVectorBuilder &, BreedingOperator &) = &ndga::Session::build;
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
            .def("evalOneMax", &ndga::EvaluationFunctions::evalOneMax, return_value_policy<manage_new_object>())
            .def("evalNarrowedOneMax", &ndga::EvaluationFunctions::evalNarrowedOneMax, return_value_policy<manage_new_object>())
            .def("evalDeceptiveOneMax", &ndga::EvaluationFunctions::evalDeceptiveOneMax, return_value_policy<manage_new_object>());
}