#ifndef RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
#define RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H


#include "../common/VectorIndividual.h"
#include "../../core/util/Thread.h"

namespace ndga {

    /**
     * A collection of common evaluation functions for Neuro-Dynamic Genetic Algorithms (NDGAs).
     *
     * @author  Felix Voelker
     * @version 0.0.2
     * @since   11.1.2018
     */
    class EvaluationFunctions {

    public:
        /**
         * Problem of finding the bit vector with the highest number of ones possible.
         */
        struct OneMaxProblem {

            /**
             * Sets the fitness to the number of zeros in the bit vector.
             */
            std::function<void(Individual &, Thread &)> operator()();
        };

    };
}


#endif //RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
