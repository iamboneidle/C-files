#pragma once
#include <vector>

using namespace std;


class Plane {
private:
    float _width;
    float _height;
    vector<float> _coordinates;

public:
    Plane(float width, float height);

    float getWidth();

    float getHeight();

    float getXCoordinate();

    float getYCoordinate();
};
