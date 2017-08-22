#include "Statistics.h"
#include "../../cc/toolbox/ec/common/RawFitness.h"

using namespace boost::python;

Statistics::Statistics(Session &session) {
    best_fitnesses = vector<float>(session.generations + 1);
    average_fitnesses = vector<float>(session.generations + 1);
    worst_fitnesses = vector<float>(session.generations + 1);
}

void Statistics::record(Population &pop, unsigned int generation) {
    best_fitnesses.at(generation) = dynamic_cast<RawFitness &>(pop.bestIndividual()->getFitness()).getFitness();
    worst_fitnesses.at(generation) = dynamic_cast<RawFitness &>(pop.worstIndividual()->getFitness()).getFitness();
    average_fitnesses.at(generation) = averageFitness(pop);
}

float Statistics::averageFitness(Population &pop) {
    vector<Individual *> &individuals = pop.getIndividuals();
    float total_fitness = 0;
    for (auto ind : individuals)
        total_fitness += dynamic_cast<RawFitness &>(ind->getFitness()).getFitness();
    return total_fitness / individuals.size();
}

void Statistics::print() {
    Py_Initialize();
    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");

    list best_fitness;
    for (float f : this->best_fitnesses)
        best_fitness.append(f);
    main_namespace["best_fitness"] = best_fitness;

    list average_fitness;
    for (float f : this->average_fitnesses)
        average_fitness.append(f);
    main_namespace["average_fitness"] = average_fitness;

    list worst_fitness;
    for (float f : this->worst_fitnesses)
        worst_fitness.append(f);
    main_namespace["worst_fitness"] = worst_fitness;

    exec("import numpy as np\n"
            "import matplotlib.pyplot as plt"
            "\n"
            "generations = np.arange(len(best_fitness))\n"
            "best = np.array(best_fitness)\n"
            "average = np.array(average_fitness)\n"
            "worst = np.array(worst_fitness)\n"
            "\n"
            "plt.plot(generations, best, label='Best')\n"
            "plt.plot(generations, average, label='Average')\n"
            "plt.plot(generations, worst, label='Worst')\n"
            "plt.xlabel('Generation')\n"
            "plt.xlim(0, generations.shape[0])\n"
            "plt.ylabel('Fitness Value')\n"
            "plt.legend()\n"
            "plt.show()",
         main_namespace);
}