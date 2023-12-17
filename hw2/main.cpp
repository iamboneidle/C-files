#include <iostream>
#include "Box.h"
#include "Trapezoid.h"
#include "Tree.h"


int main() {
    Box* square0 = new Box(vector<float>{2, 14}, vector<float>{4, 16});
    Box* square1 = new Box(vector<float>{1, 1}, vector<float>{3, 3});
    Box* square2 = new Box(vector<float>{13, 7}, vector<float>{16, 10});
    Box* square3 = new Box(vector<float>{8, 10}, vector<float>{11, 13});
    Box* square4 = new Box(vector<float>{12, 3}, vector<float>{14, 5});
    Box* square5 = new Box(vector<float>{18, 10}, vector<float>{20, 12});
    Box* square6 = new Box(vector<float>{4, 8}, vector<float>{5, 9});
    Box* square7 = new Box(vector<float>{10, 8}, vector<float>{11, 9});
    vector<Box*> vectorOfBoxes = {square0, square1, square2, square3, square4, square5, square6, square7};
    Trapezoid* trapezoid = new Trapezoid({0, 0}, 40, 0, 45, 45);
    Tree* tree = new Tree(vectorOfBoxes);
    vector<Box*> answer;
    tree->orderTravers(tree->getRoot(), answer, *trapezoid);
    cout << "u see these boxes:" << endl;
    for (Box* box: answer) {
        cout << box->getUpperRight().at(0) << " " << box->getUpperRight().at(1) << endl;
    }
    for (Box* box: vectorOfBoxes) {
        delete box;
    }
    return 0;
}
