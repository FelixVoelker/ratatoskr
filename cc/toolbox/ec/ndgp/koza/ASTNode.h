#ifndef NDEC_ASTNODE_H
#define NDEC_ASTNODE_H

#include <string>

/**
 * Represents a blueprint node for an Abstract Syntax Tree-individual in NDGP.
 * @author Felix Voelker
 * @version 0.1
 * @since 6.5.2017
 */
class ASTNode {

private:
    ASTNode** children;
    int at_depth;
    int depth;

public:
    ASTNode();
    ~ASTNode();

    virtual float eval(float input) = 0;
    virtual int expectedChildren() = 0;
    virtual std::string toString() = 0;

    /**
     *
     * @return
     */
    std::string printNode();

    ASTNode** getChildren();
    int atDepth();
    int getDepth();
    void setAtDepth(int at_depth);
    void setDepth(int depth);

};


#endif //NDEC_NDGPNODE_H
