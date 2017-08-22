#include <boost/python.hpp>
#include "../../core/evaluation/Problem.h"
#include "../../core/Session.h"
#include "../../core/EvolutionarySystem.h"


using namespace boost::python;

struct ProblemWrapper : Problem, wrapper<Problem> {

    explicit ProblemWrapper(unsigned int popsize) : Problem(popsize) {}

    void evaluate(Individual &individual) {
        this->get_override("evaluate")(individual);
    }
};

struct SessionWrapper : Session, wrapper<Session> {

private:
    void builder(Builder &builder_prototype) {}
    void fitness(Fitness &fitness_prototype) {}
    void featuremap(FeatureMap &featuremap_prototype) {}
    void individual(Individual &individual_prototype) {}
    void pipeline(BreedingOperator &pipeline_prototype) {}

public:
    explicit SessionWrapper(shared_ptr<Problem> problem) : Session(*problem) {}

};

class SystemWrapper : public EvolutionarySystem {

public:
    explicit SystemWrapper(shared_ptr<Session> session) : EvolutionarySystem(*session) {}

};

BOOST_PYTHON_MODULE(core) {
    class_<ProblemWrapper, boost::noncopyable>("Problem", init<unsigned int>())
            .def_readwrite("popsize", &Problem::popsize)
            .def("evaluate", pure_virtual(&Problem::evaluate));
    class_<SessionWrapper, boost::noncopyable>("Session", init<shared_ptr<Problem>>());
    class_<SystemWrapper>("EvolutionarySystem", init<shared_ptr<Session>>())
            .def("run", &EvolutionarySystem::run);
    /*class_<ProblemWrapper, boost::noncopyable>("Problem")
            //.def_readwrite("popsize", &Problem::popsize)
            .def("evaluate", pure_virtual(&Problem::evaluate));*/

    /*class_<Session>("Session", init<Problem>())
            .def_readwrite("generations", &Session::generations)
            .def_readwrite("evalthreads", &Session::evalthreads)
            .def_readwrite("breedthreads", &Session::breedthreads)
            .def("builder", pure_virtual(&Session::builder))
            .def("fitness", pure_virtual(&Session::fitness))
            .def("featuremap", pure_virtual(&Session::featuremap))
            .def("individual", pure_virtual(&Session::individual))
            .def("pipeline", pure_virtual(&Session::pipeline));

    class_<EvolutionarySystem>("EvolutionarySystem", init<Session>())
            .def("run", &EvolutionarySystem::run);

    class_<Builder>("Builder", init<Session>())
            .def("initialize", pure_virtual(&Builder::initialize));

    class_<FeatureMap>("FeatureMap", init<Session>());

    class_<Fitness>("Fitness", init<Session>())
            .def("isideal", pure_virtual(&Fitness::isIdeal))
            .def(pure_virtual(self < self))
            .def(pure_virtual(self <= self))
            .def(pure_virtual(self > self))
            .def(pure_virtual(self >= self))
            .def(pure_virtual(self == self));

    class_<Individual>("Individual", init<Session>())
            .def("tostring", &Individual::toString);

    class_<BreedingOperator, bases(VariationSource)>("BreedingOperator", init<Session>())
            .def("breed", pure_virtual(&BreedingOperator::breed));

    class_<SelectionOperator, bases(VariationSource)>("SelectionOperator", init<Session>())
            .def("select", pure_virtual(&SelectionOperator::select));*/
}