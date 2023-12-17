#include "QuadTree.h"


QuadTree::QuadTree(Node* *rootNode) {
    this->_root = rootNode;
}

QuadTree::~QuadTree() {
    delete this->_root;
}

Node* QuadTree::getRoot() {
    return this->_root;
}

bool QuadTree::isCollision(Circle* circle1, Circle* circle2) {
    float distance = sqrt(pow(circle1->getCoordinates().at(0) - circle2->getCoordinates().at(0), 2) +
                          pow(circle1->getCoordinates().at(1) - circle2->getCoordinates().at(1), 2));
    return distance <= (circle1->getRadius() + circle2->getRadius());
}

void QuadTree::swapVelocities(Circle* circle1, Circle* circle2) {
    float velocity;
    velocity = circle1->getVelocity().at(0);
    circle1->setVelocityX(circle2->getVelocity().at(0));
    circle2->setVelocityX(velocity);
    velocity = circle1->getVelocity().at(1);
    circle1->setVelocityY(circle2->getVelocity().at(1));
    circle2->setVelocityY(velocity);
    if (circle1->getVelocity().at(1) == 0 && circle2->getVelocity().at(0) == 1) {
        circle1->setCoordinateX(circle1->getCoordinates().at(0) + (circle1->getVelocity().at(0) / abs(circle1->getVelocity().at(0))));
        circle2->setCoordinateX(circle2->getCoordinates().at(0) + (circle2->getVelocity().at(0) / abs(circle2->getVelocity().at(0))));
    } else if (circle1->getVelocity().at(0) == 0 && circle2->getVelocity().at(0) == 0) {
        circle1->setCoordinateY(circle1->getCoordinates().at(1) + (circle1->getVelocity().at(1) / abs(circle1->getVelocity().at(1))));
        circle2->setCoordinateY(circle2->getCoordinates().at(1) + (circle2->getVelocity().at(1) / abs(circle2->getVelocity().at(1))));
    } else {
        circle1->setCoordinateX(circle1->getCoordinates().at(0) + (circle1->getVelocity().at(0) / abs(circle1->getVelocity().at(0))));
        circle2->setCoordinateX(circle2->getCoordinates().at(0) + (circle2->getVelocity().at(0) / abs(circle2->getVelocity().at(0))));
        circle1->setCoordinateY(circle1->getCoordinates().at(1) + (circle1->getVelocity().at(1) / abs(circle1->getVelocity().at(1))));
        circle2->setCoordinateY(circle2->getCoordinates().at(1) + (circle2->getVelocity().at(1) / abs(circle2->getVelocity().at(1))));
    }
}

void QuadTree::isEdgeCollision(Circle* circle, Plane* plane) {
    if ((circle->getCoordinates().at(0) + circle->getRadius() >= (plane->getXCoordinate() + plane->getWidth() / 2) ||
         circle->getCoordinates().at(0) - circle->getRadius() <= (plane->getXCoordinate() - plane->getWidth() / 2))) {
        circle->setVelocityX(- circle->getVelocity().at(0));
        circle->setCoordinateX(circle->getCoordinates().at(0) + (circle->getRadius() * circle->getVelocity().at(0) / abs(circle->getVelocity().at(0))));
        return;
    }
    if ((circle->getCoordinates().at(1) + circle->getRadius() >= (plane->getYCoordinate() + plane->getHeight() / 2) ||
         circle->getCoordinates().at(1) - circle->getRadius() <= (plane->getYCoordinate() - plane->getHeight() / 2))) {
        circle->setVelocityY(- circle->getVelocity().at(1));
        circle->setCoordinateY(circle->getCoordinates().at(1) + (circle->getRadius() * circle->getVelocity().at(1) / abs(circle->getVelocity().at(1))));
        return;
    } else {
        return;
    }
}

void QuadTree::orderTravers(Node* node, Plane* plane) {
    if (!node->getIsDivided()) {
        for (Circle *circle1: node->getCircles()) {
            isEdgeCollision(circle1, plane);
            for (Circle *circle2: node->getCircles()) {
                if (circle1 != circle2) {
                    if (isCollision(circle1, circle2)) {
                        swapVelocities(circle1, circle2);
                    }
                }
            }
        }
        return;
    } else {
        orderTravers(node->getBottomRight(), plane);
        orderTravers(node->getBottomLeft(), plane);
        orderTravers(node->getTopRight(), plane);
        orderTravers(node->getTopLeft(), plane);
    }
}

bool QuadTree::insert(Circle* circle, Node* node) {
    if (!node->getBox()->isContains(circle)) {
        return false;
    }
    if (node->getCircles().size() < node->getCapacity()) {
        node->pushCircle(circle);
        return true;
    } else {
        if (!node->getIsDivided()) {
            subdivide(node);
            for (Circle* circle0 : node->getCircles()) {
                if (insert(circle0, node->getTopLeft())) {
                    continue;
                } else if (insert(circle0, node->getTopRight())) {
                    continue;
                } else if (insert(circle0, node->getBottomLeft())) {
                    continue;
                } else if (insert(circle0, node->getBottomRight())) {
                    continue;
                }
            }
        }
        if(insert(circle, node->getTopLeft())) {return true;}
        if(insert(circle, node->getTopRight())) {return true;}
        if(insert(circle, node->getBottomLeft())) {return true;}
        if(insert(circle, node->getBottomRight())) {return true;}
    }
}

void QuadTree::subdivide(Node* node) {
    node->setBottomLeft(new Node(new Box(node->getBox()->getXCoord() - (node->getBox()->getWidth() / 4),
                                         node->getBox()->getYCoord() - (node->getBox()->getHeight() / 4),
                                         node->getBox()->getWidth() / 2, node->getBox()->getHeight() / 2),
                                 node, nullptr, nullptr, nullptr, nullptr));
    node->setBottomRight(new Node(new Box(node->getBox()->getXCoord() + (node->getBox()->getWidth() / 4),
                                          node->getBox()->getYCoord() - (node->getBox()->getHeight() / 4),
                                          node->getBox()->getWidth() / 2, node->getBox()->getHeight() / 2),
                                  node, nullptr, nullptr, nullptr, nullptr));
    node->setTopLeft(new Node(new Box(node->getBox()->getXCoord() - (node->getBox()->getWidth() / 4),
                                      node->getBox()->getYCoord() + (node->getBox()->getHeight() / 4),
                                      node->getBox()->getWidth() / 2, node->getBox()->getHeight() / 2),
                              node, nullptr, nullptr, nullptr, nullptr));
    node->setTopRight(new Node(new Box(node->getBox()->getXCoord() + (node->getBox()->getWidth() / 4),
                                       node->getBox()->getYCoord() + (node->getBox()->getHeight() / 4),
                                       node->getBox()->getWidth() / 2, node->getBox()->getHeight() / 2),
                               node, nullptr, nullptr, nullptr, nullptr));
    node->setIsDivided(true);
}
