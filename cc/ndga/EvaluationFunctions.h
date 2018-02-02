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
         * The evaluation function of the one max problem, i.e. the problem of finding the bit vector with the highest
         * number of ones possible.
         */
        class OneMaxEval : public EvaluationFunction {

        public:
            explicit OneMaxEval();

            EvaluationFunction * clone() const override;

            void operator()(Individual &individual, Thread &thread) override;

        protected:
            OneMaxEval(const OneMaxEval &obj) = default;
        };

        /**
         * The evaluation function of the one max problem, i.e. the problem of finding the bit vector with the highest
         * number of ones possible. However, the fitness is squeezed through an evaluation bottleneck.
         */
        class NarrowedOneMaxEval : public EvaluationFunction {

        public:
            explicit NarrowedOneMaxEval();

            EvaluationFunction * clone() const override;

            void operator()(Individual &individual, Thread &thread) override;

        protected:
            NarrowedOneMaxEval(const NarrowedOneMaxEval &obj) = default;
        };

        /**
         * The evaluation function of the one max problem, i.e. the problem of finding the bit vector with the highest
         * number of ones possible. However, the fitness leads to the wrong search gradient deliberately.
         */
        class DeceptiveOneMaxEval : public EvaluationFunction {

        public:
            explicit DeceptiveOneMaxEval();

            EvaluationFunction * clone() const override;

            void operator()(Individual &individual, Thread &thread) override;

        protected:
            DeceptiveOneMaxEval(const DeceptiveOneMaxEval &obj) = default;
        };

    public:
        static EvaluationFunction * evalOneMax();
        static EvaluationFunction * evalNarrowedOneMax();
        static EvaluationFunction * evalDeceptiveOneMax();

    };
}


#endif //RATATOSKR_NDGA_EVALUATIONFUNCTIONS_H
