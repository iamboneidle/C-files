#pragma once
#include <vector>
#include <cmath>
#include "Box.h"
#include "Trapezoid.h"
using namespace std;


class Node {
private:
    Box *_box;
    Node *_leftChild;
    Node *_rightChild;
    Node* _parent;
public:
    Node(Box *box, Node *leftChild, Node *rightChild, Node* parent);

    ~Node();

    Box* getBox();

    Node* getLeftChild();

    Node* getRightChild();

    Node* getParent();

    void setLeftChild(Node *newLeft);

    void setRightChild(Node *newRight);
};


class Tree {
private:
    Node *_root;
public:
    Tree(vector<Box *> vectorOfBoxes);
    ~Tree();

    Box* makeOuterBox(vector<Box *> vectorOfBoxes);

    void orderTravers(Node *node, vector<Box *> &vectorOfBoxes, const Trapezoid &trapezoid);

    void createTree(vector<Box *> vectorOfBoxes, Node *node);

    Node* getRoot();

    static bool checkBox(Box *box, Trapezoid trapezoid);
};
