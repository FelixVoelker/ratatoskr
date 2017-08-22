#include "KozaFitness.h"

float KozaFitness::adjustedFitness() {
    return 1 / (1 + standarized_fitness);
}

bool KozaFitness::isIdeal() {
    return standarized_fitness == 0;
}

float KozaFitness::standarizedFitness() {
    return standarized_fitness;
}

void KozaFitness::setStandarizedFitness(float standarized_fitness) {
    this->standarized_fitness = standarized_fitness;
}

bool KozaFitness::operator<(Fitness& other) {
    return this->standarized_fitness > ((KozaFitness&) other).standarized_fitness;
}

bool KozaFitness::operator<=(Fitness& other) {
    return this->standarized_fitness >= ((KozaFitness&) other).standarized_fitness;
}

bool KozaFitness::operator>(Fitness& other) {
    return this->standarized_fitness < ((KozaFitness&) other).standarized_fitness;
}

bool KozaFitness::operator>=(Fitness& other) {
    return this->standarized_fitness <= ((KozaFitness&) other).standarized_fitness;
}

bool KozaFitness::operator==(Fitness& other) {
    return this->standarized_fitness == ((KozaFitness&) other).standarized_fitness;
}

KozaFitness* KozaFitness::clone() {
    return new KozaFitness(*this);
}