#ifndef RATATOSKR_TRANSITIONTABLE_H
#define RATATOSKR_TRANSITIONTABLE_H


#include "../../core/experience/EvolutionaryNetwork.h"
#include "Configuration.h"

/**
 * @author  FelixVoelker
 * @version 0.1.0
 * @since   25.1.2018
 */
class TransitionTable : public EvolutionaryNetwork {

public:
    explicit TransitionTable(const common::Configuration &configuration);
    ~TransitionTable();

    std::vector<float> output(std::vector<Individual *> &individuals) const override;
    void update(std::vector<Individual *> &parents, std::vector<Individual *> &offsprings) override;

protected:
    std::vector<std::vector<float>> *lookup_table;

    std::vector<unsigned int> preprocess(std::vector<Individual *> &individuals) const override;

};


#endif //RATATOSKR_TRANSITIONTABLE_H
