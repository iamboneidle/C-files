#pragma once
#include <vector>
#include <cmath>
using namespace std;


class Trapezoid {
private:
    vector<float> _point;
    float _fov;
    float _azimuth;
    float _alpha0;
    float _alpha1;
    float _b0;
    float _b1;
    float _b2;
    float _b3;
    const float PI = 3.1415926;
public:
    Trapezoid(vector<float> _point, float _fov, float _closerEdge, float _fatherEdge, float _azimuth);

    float getAzimuth() const;

    float getAlpha0() const;

    float getAlpha1() const;

    float getB0() const;

    float getB1() const;

    float getB2() const;

    float getB3() const;
};
