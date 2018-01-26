#ifndef RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
#define RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H


#include "../../core/evaluation/EvaluationFunction.h"

namespace ndga {

    /**
     * A collection of common evaluation functions for Neuro-Dynamic Genetic Algorithms (NDGAs).
     *
     * @author  Felix Voelker
     * @version 0.1.1
     * @since   26 .1.2018
     */
    class EvaluationFunctions {

        /**
         * Problem of finding the bit vector with the highest number of ones possible.
         */
        class OneMaxEval : public EvaluationFunction {

        public:
            explicit OneMaxEval();

            EvaluationFunction * clone() const override;

            void operator()(Individual &individual, Thread &thread) override;

        protected:
            OneMaxEval(const OneMaxEval &obj) = default;
        };

    public:
        static EvaluationFunction * oneMaxEval();

    };
}


#endif //RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
