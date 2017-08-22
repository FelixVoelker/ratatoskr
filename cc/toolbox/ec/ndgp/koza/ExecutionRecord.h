#ifndef NDEC_EXECUTIONRECORD_H
#define NDEC_EXECUTIONRECORD_H

#include <deque>

/**
 *
 * @author Felix Voelker
 * @version 0.1
 * @since
 */
class ExecutionRecord /*: public FeatureMap*/ {

private:
    std::deque<std::deque<float>*>* execution_record;

public:
    //TODO: Include Problem
    ExecutionRecord(int depth, int tests);
    ~ExecutionRecord();

    float** extractFeatures();

    std::deque<float>* initializeTest();
};


#endif //NDEC_EXECUTIONRECORD_H
