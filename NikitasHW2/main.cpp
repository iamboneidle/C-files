#include "QuadTree.h"
#include <iostream>

using namespace std;

int main() {
    Plane* plane = new Plane(500, 500);
    Box* rootBox = new Box(plane->getXCoordinate(), plane->getYCoordinate(), plane->getWidth(), plane->getHeight());
    Node* rootNode = new Node(rootBox, nullptr, nullptr, nullptr, nullptr, nullptr);
    QuadTree* tree = new QuadTree(rootNode);
    vector<Circle*> vecOfCircles;
    Circle* circle1 = new Circle(5, {15, 30}, {250, 125});
    Circle* circle2 = new Circle(5, {-6, -30}, {250, 375});
    Circle* circle3 = new Circle(5, {6, 12}, {125, 250});
    Circle* circle4 = new Circle(5, {3, -3}, {375, 250});
    Circle* circle5 = new Circle(5, {6, 24}, {20, 20});
    Circle* circle6 = new Circle(5, {-9, -21}, {20, 300});

    tree->insert(circle1, rootNode);
    tree->insert(circle2, rootNode);
    tree->insert(circle3, rootNode);
    tree->insert(circle4, rootNode);
    tree->insert(circle5, rootNode);
    tree->insert(circle6, rootNode);
    vecOfCircles.push_back(circle1);
    vecOfCircles.push_back(circle2);
    vecOfCircles.push_back(circle3);
    vecOfCircles.push_back(circle4);
    vecOfCircles.push_back(circle5);
    vecOfCircles.push_back(circle6);


    float t = 0;
    float dt = 0.1;

    while(t < 100) {
        tree->orderTravers(tree->getRoot(), plane);

        for(Circle* circle : vecOfCircles) {
            circle->setCoordinateX(circle->getCoordinates().at(0) + circle->getVelocity().at(0) * dt);
            circle->setCoordinateY(circle->getCoordinates().at(1) + circle->getVelocity().at(1) * dt);
        }
        t += dt;
        rootNode = new Node(rootBox, nullptr, nullptr, nullptr, nullptr, nullptr);
        QuadTree* tree1 = tree;
        tree = new QuadTree(rootNode);
        delete tree1;

        for (Circle* circle : vecOfCircles) {
            cout << circle->getCoordinates().at(0) << "," << circle->getCoordinates().at(1) << "," << circle->getRadius() << ","  << t << endl;
            tree->insert(circle, rootNode);
        }
    }
    delete tree;
    delete rootBox;
    delete plane;
    return 0;
}
