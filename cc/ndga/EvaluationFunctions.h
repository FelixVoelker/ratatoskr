#ifndef RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
#define RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H


#include "../common/VectorIndividual.h"
#include "../../core/util/Thread.h"

namespace ndga {

    /**
     * A collection of common evaluation functions for Neuro-Dynamic Genetic Algorithms (NDGAs).
     *
     * @author  Felix Voelker
     * @version 0.1.0
     * @since   19.1.2018
     */
    class EvaluationFunctions {

    public:
        /**
         * Problem of finding the bit vector with the highest number of ones possible.
         */
        static std::function<void(Individual &, Thread &)> oneMax();

    };
}


#endif //RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
