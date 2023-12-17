#pragma once
#include <vector>
#include "Circle.h"
#include "Plane.h"
#include "Box.h"

using namespace std;


class Node {
private:
    Box* _box;
    Node* _parent;
    Node* _bottom_left;
    Node* _bottom_right;
    Node* _top_left;
    Node* _top_right;
    vector<Circle*> _circles;
    static const int _capacity = 4;
    bool _is_divided = false;

public:
    Node(Box* box, Node* parent, Node* bottom_left, Node* bottom_right, Node* top_left, Node* top_right);

    ~Node();

    int getCapacity();

    bool getIsDivided();

    Box* getBox();

    Node* getParent();

    Node* getBottomLeft();

    Node* getBottomRight();

    Node* getTopLeft();

    Node* getTopRight();

    vector<Circle*> getCircles();

    void pushCircle(Circle* circle);

    void setBottomLeft(Node* new_bottom_left);

    void setBottomRight(Node* new_bottom_right);

    void setTopLeft(Node* new_top_left);

    void setTopRight(Node* new_top_right);

    void setIsDivided(bool state);
};
