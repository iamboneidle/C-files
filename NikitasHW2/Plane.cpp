#include "Plane.h"


Plane::Plane(float width, float height) {
    this->_width = width;
    this->_height = height;
    this->_coordinates.push_back(this->_width / 2);
    this->_coordinates.push_back(this->_height / 2);
}

float Plane::getWidth() {
    return this->_width;
}

float Plane::getHeight() {
    return this->_height;
}

float Plane::getXCoordinate() {
    return this->_coordinates.at(0);
}

float Plane::getYCoordinate() {
    return this->_coordinates.at(1);
}
