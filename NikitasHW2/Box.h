#pragma once
#include <vector>
#include "Node.h"
#include "Circle.h"
#include "Plane.h"

using namespace std;


class Box {
private:
    float _x_coord;
    float _y_coord;
    float _width;
    float _height;
    vector<Circle*> _vectorOfBalls;

public:
    Box(float x_coord, float y_coord, float width, float height);

    vector<Circle*> getVectorOfBalls();

    void pushToVectorOfBalls(Circle* circle);

    float getXCoord();

    float getYCoord();

    float getWidth();

    float getHeight();

    bool isContains(Circle* circle);
};
