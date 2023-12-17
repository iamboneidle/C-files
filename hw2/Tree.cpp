#include "Tree.h"


Node::Node(Box *box, Node *leftChild, Node *rightChild, Node *parent) {
    this->_box = box;
    this->_leftChild = leftChild;
    this->_rightChild = rightChild;
    this->_parent = parent;
}

Node::~Node() {
    delete this->_box;
    delete this->_leftChild;
    delete this->_rightChild;
    delete this->_parent;
}

Box* Node::getBox() {
    return _box;
}

Node* Node::getLeftChild() {
    return _leftChild;
}

Node* Node::getParent() {
    return _parent;
}

Node* Node::getRightChild() {
    return _rightChild;
}

void Node::setLeftChild(Node *newLeft) {
    this->_leftChild = newLeft;
}

void Node::setRightChild(Node *newRight) {
    this->_rightChild = newRight;
}


Tree::Tree(vector<Box *> vectorOfBoxes) {
    Box *rootBox = makeOuterBox(vectorOfBoxes);
    this->_root = new Node(rootBox, nullptr, nullptr, nullptr);
    createTree(vectorOfBoxes, this->_root);
}

Tree::~Tree() {
    delete this->_root;
}

Box* Tree::makeOuterBox(vector<Box *> vectorOfBoxes) {
    float maxX = -MAXFLOAT;
    float maxY = -MAXFLOAT;
    float minX = MAXFLOAT;
    float minY = MAXFLOAT;
    for (Box *box: vectorOfBoxes) {
        if (box->getUpperRight().at(0) > maxX) {
            maxX = box->getUpperRight().at(0);
        }
        if (box->getUpperRight().at(1) > maxY) {
            maxY = box->getUpperRight().at(1);
        }
        if (box->getDownLeft().at(0) < minX) {
            minX = box->getDownLeft().at(0);
        }
        if (box->getDownLeft().at(1) < minY) {
            minY = box->getDownLeft().at(1);
        }
    }
    vector<float> downLeft = {minX, minY};
    vector<float> upperRight = {maxX, maxY};
    return new Box(downLeft, upperRight);
}

void Tree::orderTravers(Node *node, vector<Box *> &vectorOfBoxes, const Trapezoid &trapezoid) {
    if (node != nullptr) {
        if (checkBox(node->getBox(), trapezoid)) {
            if ((node->getLeftChild() == nullptr || node->getRightChild() == nullptr)) {
                vectorOfBoxes.push_back(node->getBox());
            }
            orderTravers(node->getLeftChild(), vectorOfBoxes, trapezoid);
            orderTravers(node->getRightChild(), vectorOfBoxes, trapezoid);
        } else {
            if (node->getParent() != getRoot() && node->getParent()) {
                if (node->getParent()->getLeftChild() == node) {
                    orderTravers(node->getRightChild(), vectorOfBoxes, trapezoid);
                } else if (node->getParent()->getRightChild() == node) {
                    orderTravers(node->getLeftChild(), vectorOfBoxes, trapezoid);
                }
            } else {
                if (getRoot()->getLeftChild() == node && node->getParent()) {
                    orderTravers(node->getParent()->getRightChild(), vectorOfBoxes, trapezoid);
                } else if(node->getParent()) {
                    orderTravers(node->getParent()->getLeftChild(), vectorOfBoxes, trapezoid);
                }
            }
        }
    }
}

void Tree::createTree(vector<Box *> vectorOfBoxes, Node *node) {
    vector<Box *> leftHalf(vectorOfBoxes.begin(), vectorOfBoxes.begin() + vectorOfBoxes.size() / 2);
    vector<Box *> rightHalf(vectorOfBoxes.begin() + vectorOfBoxes.size() / 2, vectorOfBoxes.end());
    Node *leftChild = new Node(makeOuterBox(leftHalf), nullptr, nullptr, node);
    Node *rightChild = new Node(makeOuterBox(rightHalf), nullptr, nullptr, node);
    node->setLeftChild(leftChild);
    node->setRightChild(rightChild);
    if (leftHalf.size() == 1) {
        return;
    }
    createTree(leftHalf, leftChild);
    if (rightHalf.size() == 1) {
        return;
    }
    createTree(rightHalf, rightChild);
}

Node* Tree::getRoot() {
    return _root;
}

bool Tree::checkBox(Box *box, Trapezoid trapezoid) {
    if ((box->getDownLeft().at(1) < trapezoid.getAlpha0() * box->getDownLeft().at(0) + trapezoid.getB0()) &&
        (box->getDownLeft().at(1) > trapezoid.getAlpha1() * box->getDownLeft().at(0) + trapezoid.getB1()) &&
        (box->getDownLeft().at(1) > -box->getDownLeft().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB2()) &&
        (box->getDownLeft().at(1) < -box->getDownLeft().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB3())) {
        return true;
    } else if (
            (box->getDownRight().at(1) < trapezoid.getAlpha0() * box->getDownRight().at(0) + trapezoid.getB0()) &&
            (box->getDownRight().at(1) > trapezoid.getAlpha1() * box->getDownRight().at(0) + trapezoid.getB1()) &&
            (box->getDownRight().at(1) >
             -box->getDownRight().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB2()) &&
            (box->getDownRight().at(1) <
             -box->getDownRight().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB3())) {
        return true;
    } else if (
            (box->getUpperRight().at(1) < trapezoid.getAlpha0() * box->getUpperRight().at(0) + trapezoid.getB0()) &&
            (box->getUpperRight().at(1) > trapezoid.getAlpha1() * box->getUpperRight().at(0) + trapezoid.getB1()) &&
            (box->getUpperRight().at(1) >
             -box->getUpperRight().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB2()) &&
            (box->getUpperRight().at(1) <
             -box->getUpperRight().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB3())) {
        return true;
    } else if (
            (box->getUpperLeft().at(1) < trapezoid.getAlpha0() * box->getUpperLeft().at(0) + trapezoid.getB0()) &&
            (box->getUpperLeft().at(1) > trapezoid.getAlpha1() * box->getUpperLeft().at(0) + trapezoid.getB1()) &&
            (box->getUpperLeft().at(1) >
             -box->getUpperLeft().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB2()) &&
            (box->getUpperLeft().at(1) <
             -box->getUpperLeft().at(0) / tan(trapezoid.getAzimuth()) + trapezoid.getB3())) {
        return true;
    } else { return false; }
}













