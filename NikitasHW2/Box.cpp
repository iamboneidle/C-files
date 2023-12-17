#include "Box.h"


Box::Box(float x_coord, float y_coord, float width, float height) {
    this->_x_coord = x_coord;
    this->_y_coord = y_coord;
    this->_width = width;
    this->_height = height;
}

vector<Circle*> Box::getVectorOfBalls() {
    return this->_vectorOfBalls;
}

void Box::pushToVectorOfBalls(Circle* circle) {
    this->_vectorOfBalls.push_back(circle);
}

float Box::getXCoord() {
    return this->_x_coord;
}

float Box::getYCoord() {
    return this->_y_coord;
}

float Box::getWidth() {
    return this->_width;
}

float Box::getHeight() {
    return this->_height;
}

bool Box::isContains(Circle* circle) {
    if ((circle->getCoordinates().at(0) <= this->_x_coord + this->_width / 2 &&
         circle->getCoordinates().at(0) >= this->_x_coord - this->_width / 2) &&
        (circle->getCoordinates().at(1) <= this->_y_coord + this->_height / 2 &&
         circle->getCoordinates().at(1) >= this->_y_coord - this->_height / 2)) {
        return true;
    }else {return false;}
    // TODO написать граничное условие, если центр шарика находится в квадрате, но куском вылезает в другой квадрат
}