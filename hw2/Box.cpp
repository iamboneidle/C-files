#include "Box.h"


Box::Box(vector<float> _downLeft, vector<float> _upperRight) {
    this->_downLeft = std::move(_downLeft);
    this->_upperRight = std::move(_upperRight);
    this->_upperLeft.push_back(this->_downLeft.at(0));
    this->_upperLeft.push_back(this->_upperRight.at(1));
    this->_downRight.push_back(this->_upperRight.at(0));
    this->_downRight.push_back(this->_downLeft.at(1));
}

vector<float> Box::getUpperRight() {
    return this->_upperRight;
}

vector<float> Box::getDownLeft() {
    return this->_downLeft;
}

vector<float> Box::getDownRight() {
    return this->_downRight;
}

vector<float> Box::getUpperLeft() {
    return this->_upperLeft;
}
