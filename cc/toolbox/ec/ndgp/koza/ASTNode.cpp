#include "ASTNode.h"

ASTNode::ASTNode() {
    //children = new ASTNode*[this->expectedChildren()];
}

ASTNode::~ASTNode() {
    delete [] children;
    children = 0;
}

std::string ASTNode::printNode() {
    if (expectedChildren() == 0)
        return toString();
    else {
        std::string s_expression = "(" + toString();
        for (int k = 0; k < expectedChildren(); k++) {
            s_expression += " " + children[k]->printNode();
        }
        s_expression += ")";
        return s_expression;
    }
}

ASTNode** ASTNode::getChildren() {
    return children;
}

int ASTNode::atDepth() {
    return at_depth;
}

int ASTNode::getDepth() {
    return depth;
}

void ASTNode::setAtDepth(int at_depth) {
    this->at_depth = at_depth;
}

void ASTNode::setDepth(int depth) {
    this->depth = depth;
}

