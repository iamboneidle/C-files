#include "Node.h"


Node::Node(Box* box, Node* parent, Node* bottom_left, Node* bottom_right, Node* top_left, Node* top_right) {
    this->_parent = parent;
    this->_bottom_left = bottom_left;
    this->_bottom_right = bottom_right;
    this->_top_left = top_left;
    this->_top_right = top_right;
    this->_box = box;
}

Node::~Node() {
    delete this->_top_right;
    delete this->_top_left;
    delete this->_bottom_right;
    delete this->_bottom_left;
}

int Node::getCapacity() {
    return _capacity;
}

bool Node::getIsDivided() {
    return this->_is_divided;
}

Box* Node::getBox() {
    return this->_box;
}

Node* Node::getParent() {
    return this->_parent;
}

Node* Node::getBottomLeft() {
    return this->_bottom_left;
}

Node* Node::getBottomRight() {
    return this->_bottom_right;
}

Node* Node::getTopLeft() {
    return this->_top_left;
}

Node* Node::getTopRight() {
    return this->_top_right;
}

vector<Circle*> Node:: getCircles() {
    return this->_circles;
}
void Node::pushCircle(Circle* circle) {
    this->_circles.push_back(circle);
}

void Node::setBottomLeft(Node* new_bottom_left) {
    this->_bottom_left = new_bottom_left;
}

void Node::setBottomRight(Node* new_bottom_right) {
    this->_bottom_right = new_bottom_right;
}

void Node::setTopLeft(Node* new_top_left) {
    this->_top_left = new_top_left;
}

void Node::setTopRight(Node* new_top_right) {
    this->_top_right = new_top_right;
}

void Node::setIsDivided(bool state) {
    this->_is_divided = state;
}
