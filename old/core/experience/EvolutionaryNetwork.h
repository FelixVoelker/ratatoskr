#ifndef RATATOSKR_EVOLUTIONARYNETWORK_H
#define RATATOSKR_EVOLUTIONARYNETWORK_H


#include "../../../core/state/Population.h"

/**
 * TODO: Comments
 * @author  Felix Voelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class EvolutionaryNetwork : public Prototype {

public:
    explicit EvolutionaryNetwork(const core::Configuration &configuration);
    virtual ~EvolutionaryNetwork() = default;

    /**
     *
     * @param individuals
     * @return
     */
    virtual std::vector<float> output(std::vector<Individual *> &individuals) const = 0;

    /**
     *
     * @param parents
     * @param offsprings
     */
    virtual void update(std::vector<float> &fitness,
                        std::vector<std::vector<float>> &parent,
                        std::vector<std::vector<float>> &offspring) = 0;

    virtual EvolutionaryNetwork * clone() const = 0;

protected:
    float learning_rate;
    float discount_factor;

    EvolutionaryNetwork(const EvolutionaryNetwork &obj);

    /**
     *
     * @param individuals
     * @return
     */
    virtual std::vector<unsigned int> preprocess(std::vector<Individual *> &individuals) const = 0;

};


#endif //RATATOSKR_EVOLUTIONARYNETWORK_H
