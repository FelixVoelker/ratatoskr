#include "Evaluator.h"

Evaluator::Evaluator(const Session &session) : Singleton(session),
                                               popsize(session.problem().popsize()),
                                               evalthreads(session.evalthreads()),
                                               eval(session.problem().eval()),
                                               network(session.network()),
                                               threads(new vector<thread>(evalthreads)) {}

Evaluator::~Evaluator() {
    delete threads;
}

void Evaluator::evaluateChunk(vector<Individual *> &individuals,
                              const unsigned int offset,
                              const unsigned int size) const {
    EvaluationFunction &e = *eval;
    for (unsigned int k = offset; k < offset + size; k++)
        e(*individuals.at(k));
}

void Evaluator::evaluatePopulation(const Population &pop) const {
    auto individuals = pop.getIndividuals();

    unsigned int offset = 0;
    auto chunk_size = static_cast<unsigned int>(individuals.size() / evalthreads);
    for (unsigned int k = 0; k < evalthreads - 1; k++) {
        threads->at(k) = thread(&Evaluator::evaluateChunk,
                               this, std::ref(individuals),
                               offset,
                               chunk_size);
        offset += chunk_size;
    }
    threads->at(evalthreads - 1) = thread(&Evaluator::evaluateChunk,
                                         this,
                                         std::ref(individuals),
                                         offset,
                                         individuals.size() - offset);

    for (auto &thread : *threads)
        thread.join();


    vector<float> cost = network->output(pop);
    for (unsigned int k = 0; k < pop.getIndividuals().size(); k++)
        pop.getIndividuals().at(k)->getRelevance().cost(cost.at(k));
}