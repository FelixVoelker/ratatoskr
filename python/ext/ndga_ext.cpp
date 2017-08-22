#include <boost/python.hpp>
#include "../../cc/toolbox/problem/ndga/OneMaxProblem.h"
#include "../../cc/toolbox/ec/ndga/NDGASession.h"
#include "../../cc/toolbox/ec/ndga/BitVectorIndividual.h"


using namespace boost::python;

class SessionWrapper : public NDGASession {

public:
    explicit SessionWrapper(shared_ptr<NDGAProblem> problem) : NDGASession(*problem) {}

};


BOOST_PYTHON_MODULE(ndga) {
    class_<ProblemWrapper, boost::noncopyable>("NDGAProblem", init<unsigned int, unsigned int>())
            .def("evaluate", pure_virtual(&Problem::evaluate));
    class_<OneMaxProblem, bases<ProblemWrapper>>("OneMaxProblem", init<unsigned int, unsigned int>());
    implicitly_convertible<shared_ptr<OneMaxProblem>, shared_ptr<NDGAProblem>>();

    class_<SessionWrapper>("NDGASession", init<shared_ptr<NDGAProblem>>());
    implicitly_convertible<shared_ptr<NDGASession>, shared_ptr<Session>>();
            //.def("xoverrate", &SessionWrapper::xover_rate)
            //.def("mutationrate", &SessionWrapper::mutation_rate);

    class_<BitVectorIndividual>("BitVectorIndividual", init<shared_ptr<Session>>())
            .def("chromosome", &BitVectorIndividual::getChromosome);

}