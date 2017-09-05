#ifndef NDEC_ASTINDIVIDUAL_H
#define NDEC_ASTINDIVIDUAL_H

#include "KozaFitness.h"
#include "ASTNode.h"

/**
 * Represents an individual in the form of an Abstract Syntax Tree (AST).
 * @author Felix Voelker
 * @version 0.1
 * @since 6.5.2017
 */
class ASTIndividual /*: public Individual*/ {

private:
    ASTNode* root;

public:
    ASTIndividual(KozaFitness* fitness, ASTNode* root);

    float exec(float input);

    std::string tostring();

};


#endif //NDEC_NDGPINDIVIDUAL_H
