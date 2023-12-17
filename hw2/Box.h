#pragma once
#include <vector>
using namespace std;


class Box {
private:
    vector<float> _upperRight;
    vector<float> _upperLeft;
    vector<float> _downRight;
    vector<float> _downLeft;
public:
    Box(vector<float> _downLeft, vector<float> _upperRight);

    vector<float> getUpperRight();

    vector<float> getDownLeft();

    vector<float> getDownRight();

    vector<float> getUpperLeft();
};
