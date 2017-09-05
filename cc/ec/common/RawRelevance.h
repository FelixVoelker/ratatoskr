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
    explicit RawRelevance(Session &session);

    float relevance(int epoch);

    float cost();
    void cost(float cost);

    RawRelevance* clone();

};


#endif //NDEC_RAWRELEVANCE_H
