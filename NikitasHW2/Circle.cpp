#include "Circle.h"


Circle::Circle(float _radius, vector<float> _velocity, vector<float> _coordinates) {
    this->_radius = _radius;
    this->_velocity = _velocity;
    this->_coordinates = _coordinates;
}

vector<float> Circle::getVelocity() {
    return this->_velocity;
}

vector<float> Circle::getCoordinates() {
    return this->_coordinates;
}

float Circle::getRadius () const {
    return this->_radius;
}

void Circle::setVelocityX(float x_velocity) {
    this->_velocity.at(0) = x_velocity;
}

void Circle::setVelocityY(float y_velocity) {
    this->_velocity.at(1) = y_velocity;
}

void Circle::setCoordinateX(float x_coordinate) {
    this->_coordinates.at(0) = x_coordinate;
}

void Circle::setCoordinateY(float y_coordinate) {
    this->_coordinates.at(1) = y_coordinate;
}
