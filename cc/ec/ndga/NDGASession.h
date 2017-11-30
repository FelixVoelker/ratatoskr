#ifndef NDEC_NDGA_H
#define NDEC_NDGA_H

#include "NDGAProblem.h"
#include "../../../core/Session.h"


/**
 * TODO: Comments
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

    void setNetwork(EvolutionaryNetwork &network) override;
    void setBuilder(Builder &builder) override;
    void setFitness(Fitness &fitness_prototype) override;
    void setCost(Cost &relevance_prototype) override;
    void setFeaturemap(FeatureMap &featuremap_prototype) override;
    void setIndividual(Individual &individual_prototype) override;
    void setPipeline(BreedingOperator &pipeline_prototype) override;

};


#endif //NDEC_NDGA_H
