#ifndef RATATOSKR_COMMON_PROBLEM_H
#define RATATOSKR_COMMON_PROBLEM_H


#include "../../core/Problem.h"
#include "Configuration.h"

namespace common {

    /**
     * Represents optimization problems that can be solved by several types of Neuro-Dynamic
     * Evolutionary Algorithms (NDEAs).
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   25.1.2018
     */
    class Problem : public core::Problem {

    public:
        Problem(std::function<void(Individual &, Thread &)> eval, unsigned int popsize, unsigned int genes);
        Problem(const Problem &obj);

    };
}


#endif //RATATOSKR_COMMON_PROBLEM_H
