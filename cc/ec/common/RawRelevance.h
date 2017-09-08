#ifndef NDEC_RAWRELEVANCE_H
#define NDEC_RAWRELEVANCE_H


#include "../../../core/representation/Relevance.h"

/**
 * @author  FelixVoelker
 * @version 0.1
 * @since   1.9.2017
 */
class RawRelevance : public Relevance {

protected:
    float _cost;

public:
    explicit RawRelevance(const Session &session);

    float relevance(int epoch) override;

    float cost() const;
    void cost(float cost);

    RawRelevance* clone() const override;

};


#endif //NDEC_RAWRELEVANCE_H
