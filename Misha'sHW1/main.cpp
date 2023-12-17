#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};


class CircleStack {
public:
    Node* first;
    Node* last;

    CircleStack() {
        this->first = nullptr;
        this->last = nullptr;
    }

    ~CircleStack() {
        delete this->first;
        delete this->last;
    }

    void addElement(CircleStack* stack, int value) {
        if (stack->first == nullptr) {
            Node* newNode = new Node(value, nullptr);
            stack->first = newNode;
            stack->last = newNode;
        }
        else {
            Node* newNode = new Node(value, stack->first);
            stack->first = newNode;
            stack->last->next = newNode;
        }
    }

    int getElement(CircleStack* stack, int position) {
        if (stack->first == nullptr) {
            return 404;
        }
        int k = 0;
        Node* curNode = stack->first;
        while (curNode->next != stack->first) {
            if (k == position) {
                return curNode->value;
            }
            else {
                curNode = curNode->next;
                k++;
            }
        }
        if (curNode->next == stack->first && k == position) return curNode->value;

        return 404;
    }

    void deleteCircleStack(CircleStack* stack) {
        Node* curNode = stack->first;
        Node* nextNode;
        while (curNode != stack->last) {
            nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
        stack->first = nullptr;
        stack->last = nullptr;
    }

    void changeElementValue(CircleStack* stack, int position, int newValue) {
        if (stack->first == nullptr) {
            cout << "ur stack is empty" << endl;
            return;
        }
        int k = 0;
        Node* curNode = stack->first;
        while (curNode->next != stack->first) {
            if (k == position) {
                curNode->value = newValue;
                return;
            }
            else {
                curNode = curNode->next;
                k++;
            }
        }
        if (curNode->next == stack->first && k == position) curNode->value = newValue;

        cout << "ur index exceeds stack.size()" << endl;
    }

    void showCircleStack(CircleStack* stack) {
        if (stack->first == nullptr) {
            cout << "ur stack is empty" << endl;
            return;
        }
        Node* curNode = stack->first;
        while (curNode->next != stack->first) {
            cout << curNode->value << endl;
            curNode = curNode->next;
        }
        if (curNode->next == stack->first) {
            cout << curNode->value << endl;
        }
    }

};



int main() {
    CircleStack* circleStack = new CircleStack();
    circleStack->addElement(circleStack, 0);
    circleStack->addElement(circleStack, 1);
    circleStack->addElement(circleStack, 2);
    circleStack->addElement(circleStack, 3);
    circleStack->addElement(circleStack, 4);
    cout << "ur stack:" << endl;
    circleStack->showCircleStack(circleStack);
    int position = 2;
    cout << "ur element at position " << position << ":" << endl;
    cout << circleStack->getElement(circleStack, position) << endl;
    circleStack->changeElementValue(circleStack, 5, 100);
    cout << "ur stack with a new element:" << endl;
    circleStack->showCircleStack(circleStack);
    circleStack->deleteCircleStack(circleStack);
    circleStack->showCircleStack(circleStack);

    return 0;
}