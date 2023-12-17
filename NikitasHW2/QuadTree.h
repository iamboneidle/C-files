#pragma once
#include <vector>
#include "Node.h"
#include "Circle.h"
#include "Plane.h"
#include "Box.h"

using namespace std;


class QuadTree {
private:
    Node* _root;
public:

    QuadTree(Node* rootNode);

    ~QuadTree();

    Node* getRoot();

    bool isCollision(Circle* circle1, Circle* circle2);

    void swapVelocities(Circle* circle1, Circle* circle2);

    void isEdgeCollision(Circle* circle, Plane* plane);

    void orderTravers(Node* node, Plane* plane);

    bool insert(Circle* circle, Node* node);

    void subdivide(Node* node);
};
