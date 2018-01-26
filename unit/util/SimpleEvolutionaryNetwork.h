#ifndef RATATOSKR_SIMPLEEVOLUTIONARYNETWORK_H
#define RATATOSKR_SIMPLEEVOLUTIONARYNETWORK_H


#include "../../core/experience/EvolutionaryNetwork.h"

/**
 * A simple instance of EvolutionaryNetwork to test core functionality.
 *
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class SimpleEvolutionaryNetwork : public EvolutionaryNetwork {

public:
    explicit SimpleEvolutionaryNetwork(const core::Configuration &configuration);

    std::vector<float> output(std::vector<Individual *> &individuals) const override;

    void update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) override;

    SimpleEvolutionaryNetwork * clone() const override;

protected:
    std::vector<unsigned int> preprocess(std::vector<Individual *> &individuals) const override;

    SimpleEvolutionaryNetwork(const SimpleEvolutionaryNetwork &obj) = default;

};


#endif //RATATOSKR_SIMPLEEVOLUTIONARYNETWORK_H
