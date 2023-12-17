#include "Trapezoid.h"


Trapezoid::Trapezoid(vector<float> _point, float _fov, float _closerEdge, float _fatherEdge, float _azimuth) {
    this->_point = std::move(_point);
    this->_fov = (_fov * PI) / 180;
    this->_azimuth = (_azimuth * PI) / 180;
    this->_alpha0 = tan(this->_azimuth + this->_fov / 2);
    this->_alpha1 = tan(this->_azimuth - this->_fov / 2);
    this->_b0 = this->_point.at(1) - this->_alpha0 * this->_point.at(0);
    this->_b1 = this->_point.at(1) - this->_alpha1 * this->_point.at(0);
    this->_b2 = this->_point.at(1) + _closerEdge * sin(this->_azimuth) +
                (this->_point.at(0) + _closerEdge * cos(this->_azimuth)) / (tan(this->_azimuth));
    this->_b3 = this->_point.at(1) + _fatherEdge * sin(this->_azimuth) +
                (this->_point.at(0) + _fatherEdge * cos(this->_azimuth)) / (tan(this->_azimuth));
}

float Trapezoid::getAzimuth() const {
    return _azimuth;
}

float Trapezoid::getAlpha0() const {
    return _alpha0;
}

float Trapezoid::getAlpha1() const {
    return _alpha1;
}

float Trapezoid::getB0() const {
    return _b0;
}

float Trapezoid::getB1() const {
    return _b1;
}

float Trapezoid::getB2() const {
    return _b2;
}

float Trapezoid::getB3() const {
    return _b3;
}
