#ifndef NDEC_NDGA_H
#define NDEC_NDGA_H

#include "NDGAProblem.h"
#include "../../../core/Session.h"


/**
 * Represents a session of conventional Neuro-Dynamic Genetic Algorithms.
 *
 * @author  Felix Voelker
 * @version 0.1
 * @since   12.7.2017
 */
class NDGASession : public Session {

public:
    double xover_rate = 0.7;
    double mutation_rate = 0.001;

    explicit NDGASession(const NDGAProblem &problem);

    void network(EvolutionaryNetwork &network) override;
    void builder(Builder &builder) override;
    void fitness(Fitness &fitness_prototype) override;
    void relevance(Relevance &relevance_prototype) override;
    void featuremap(FeatureMap &featuremap_prototype) override;
    void individual(Individual &individual_prototype) override;
    void pipeline(BreedingOperator &pipeline_prototype) override;

};


#endif //NDEC_NDGA_H
