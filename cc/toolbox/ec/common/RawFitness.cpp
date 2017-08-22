#include "RawFitness.h"

RawFitness::RawFitness(Session &session) : Fitness(session) {}

bool RawFitness::isIdeal() {
    return hits == 0;
}

bool RawFitness::operator<(Fitness &other) {
    return this->fitness < ((RawFitness &) other).fitness;
}

bool RawFitness::operator<=(Fitness &other) {
    return this->fitness <= ((RawFitness &) other).fitness;
}

bool RawFitness::operator>(Fitness &other) {
    return this->fitness > ((RawFitness &) other).fitness;
}

bool RawFitness::operator>=(Fitness &other) {
    return this->fitness >= ((RawFitness &) other).fitness;
}

bool RawFitness::operator==(Fitness &other) {
    return this->fitness == ((RawFitness &) other).fitness;
}

float RawFitness::getFitness() {
    return fitness;
}

int RawFitness::getHits() {
    return hits;
}

void RawFitness::setFitness(float fitness) {
    this->fitness = fitness;
}

void RawFitness::setHits(int hits) {
    this->hits = hits;
}

RawFitness * RawFitness::clone() {
    return new RawFitness(*this);
}

