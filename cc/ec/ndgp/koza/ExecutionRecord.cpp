#include "ExecutionRecord.h"

ExecutionRecord::ExecutionRecord(int depth, int tests) {
    execution_record = new std::deque<std::deque<float>*>();
}

ExecutionRecord::~ExecutionRecord() {
    while (!execution_record->empty()) {
        execution_record->front()->clear();
        execution_record->pop_front();
    }
    execution_record->clear();
    delete execution_record;
}

float** ExecutionRecord::extractFeatures() {
    float** features = new float*[execution_record->size()];

    int test = 0;
    while (!execution_record->empty()) {
        std::deque<float>* trace = execution_record->front();
        features[test] = new float[trace->size()];

        int instruction = 0;
        while (!trace->empty()) {
            features[test][instruction] = trace->front();
            trace->pop_front();
            instruction += 1;
        }
        execution_record->pop_front();
        test += 1;
    }

    return features;
}

std::deque<float>* ExecutionRecord::initializeTest() {
    std::deque<float>* trace = new std::deque<float>();
    execution_record->push_back(trace);
    return trace;
}


