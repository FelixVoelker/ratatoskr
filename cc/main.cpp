

#include "common/Problem.h"
#include "ndga/EvaluationFunctions.h"
#include "ndga/Session.h"

int main() {
    auto *eval = ndga::EvaluationFunctions::evalOneMax();
    auto *problem = new common::Problem(*eval, 10, 3);
    auto *session = new ndga::Session(*problem);
    session->getConfiguration().getEvolutionarySystemConfiguration().complete = true;
    session->getConfiguration().getEvolutionarySystemConfiguration().epochs = 10;
    session->getConfiguration().getEvolutionarySystemConfiguration().episodes = 1000;
    session->getConfiguration().getEvolutionarySystemConfiguration().generations = 50;
    session->getConfiguration().getEvaluatorConfiguration().threads = 3;
    session->getConfiguration().getBreederConfiguration().threads = 3;
    session->getConfiguration().getInitializerConfiguration().threads = 3;
    auto *system = session->build();
    system->run();

    delete system;
    delete session;
    delete problem;
    delete eval;
}