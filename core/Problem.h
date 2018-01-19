#ifndef RATATOSKR_CORE_PROBLEM_H
#define RATATOSKR_CORE_PROBLEM_H


#include "representation/Individual.h"
#include "util/Thread.h"

namespace core {

    /**
     * The base class for any optimization problem that is supposed to be solved by a Neuro-Dynamic Evolutionary
     * Algorithm (NDEA). These are specified by a configuration of problem-dependent parameters and an evaluation function.
     * Accordingly, a problem does not only drive the evaluation of each single individual but also assigns all
     * domain-dependent data to the components of the evolutionary system.
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   19.1.2018
     */
    class Problem {

    public:
        Problem(std::function<void(Individual &, Thread &)> eval, unsigned int popsize);
        Problem(const Problem &obj);
        ~Problem();

        const std::function<void(Individual &, Thread &)> & getEval() const;
        Configuration::ProblemConfiguration & getConfiguration();
        const Configuration::ProblemConfiguration & getConfiguration() const;
        void setEval(std::function<void(Individual &, Thread &)> eval);

    protected:
        Configuration::ProblemConfiguration *configuration;

        /**
         * Assigns a fitness value to an individual according to the specification of the problem.
         * @param individual The individual to be evaluated.
         * @param thread     The evaluating thread.
         */
        std::function<void(Individual &, Thread &)> eval;

        /**
         * Constructor for derived problems that allows to use their own ProblemConfiguration.
         */
        Problem(std::function<void(Individual &, Thread &)> eval,
                Configuration::ProblemConfiguration *configuration,
                unsigned int popsize);

    };
}


#endif // RATATOSKR_CORE_PROBLEM_H
