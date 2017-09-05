//
// Created by felix on 5/6/17.
//

#include "ASTIndividual.h"



float ASTIndividual::exec(float input) {
    return root->eval(input);
}
