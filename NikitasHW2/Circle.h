#pragma once
#include <vector>
#include "Node.h"
#include "Plane.h"
#include "Box.h"

using namespace std;


class Circle {
private:
    float _radius;
    vector<float> _velocity;
    vector<float> _coordinates;

public:
    Circle(float _radius, vector<float> _velocity, vector<float> _coordinates);

    vector<float> getVelocity();

    vector<float> getCoordinates();

    float getRadius () const;

    void setVelocityX(float x_velocity);

    void setVelocityY(float y_velocity);

    void setCoordinateX(float x_coordinate);

    void setCoordinateY(float y_coordinate);
};
