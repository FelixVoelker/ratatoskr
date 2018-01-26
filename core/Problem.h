#ifndef RATATOSKR_CORE_PROBLEM_H
#define RATATOSKR_CORE_PROBLEM_H


#include "representation/Individual.h"
#include "util/Thread.h"
#include "evaluation/EvaluationFunction.h"

namespace core {

    /**
     * The base class for any optimization problem that is supposed to be solved by a Neuro-Dynamic Evolutionary
     * Algorithm (NDEA). These are specified by a configuration of problem-dependent parameters and an evaluation function.
     * Accordingly, a problem does not only drive the evaluation of each single individual but also assigns all
     * domain-dependent data to the components of the evolutionary system.
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   25.1.2018
     */
    class Problem {

    public:
        explicit Problem(EvaluationFunction &eval, unsigned int popsize);
        Problem(const Problem &obj);
        ~Problem();

        const EvaluationFunction & getEval() const;
        Configuration::ProblemConfiguration & getConfiguration();
        const Configuration::ProblemConfiguration & getConfiguration() const;
        void setEval(EvaluationFunction &eval);

    protected:
        Configuration::ProblemConfiguration *configuration;

        EvaluationFunction *eval;

        /**
         * Constructor for derived problems that allows to use their own ProblemConfiguration.
         */
        Problem(EvaluationFunction &eval,
                Configuration::ProblemConfiguration *configuration,
                unsigned int popsize);

    };
}


#endif // RATATOSKR_CORE_PROBLEM_H
