#include <stdio.h>


struct Node {
    int value;
    Node *next;
};

struct LinkedList {
    Node *first;
    Node *last;
};

void linkedListCreate(LinkedList *list) {
    list->first = nullptr;
    list->last = nullptr;
}

void linkedListAddEnd(LinkedList *list, int value) {
    Node *node = new Node{value, nullptr};
    if (list->last) {
        list->last->next = node;
        list->last = node;
    } else {
        list->last = node;
        list->first = node;
    }
}

void linkedListAddBeginning(LinkedList *list, int value) {
    Node *node = new Node{value, list->first};
    if (!list->first) {
        list->last = node;
    }
    list->first = node;
}

void linkedListShow(const LinkedList *list) {
    if (!list->first) {
        return;
    }
    Node *curNode = list->first;
    while (curNode != nullptr) {
        printf("%i\n", curNode->value);
        curNode = curNode->next;
    }
}

void linkedListDelete(LinkedList *list) {
    Node *curNode = list->first;
    Node *nextNode;
    do {
        nextNode = curNode->next;
        delete curNode;
    } while (curNode = nextNode);
}

void linkedListSearchByVal(LinkedList *list, int value) {
    Node *curNode = list->first;
    int k = 0;
    while (curNode->next != nullptr) {
        if (curNode->value == value) {
            printf("%i\n", k);
            return;
        } else {
            curNode = curNode->next;
            k++;
        }
    }
    if (curNode->next == nullptr & curNode->value == value) {
        printf("%i\n", k);
        return;
    } else if (curNode->value != value) {
        printf("no such a variable in the list\n");
    }
}

void linkedListSearchByIndex(LinkedList *list, int index) {
    int k = 0;
    Node *curNode = list->first;
    while (curNode->next != nullptr) {
        if (k == index) {
            printf("%i\n", curNode->value);
            return;
        } else {
            k++;
            curNode = curNode->next;
        }
    }
    if (k == index) {
        printf("%i\n", curNode->value);
        return;
    } else if (index > k) {
        printf("ur index exceeds max list's index\n");
    }
}

void linkedListAddByIndex(LinkedList *list, int index, int value) {
    int k = 0;
    Node *prevNode = list->first;
    Node *curNode = prevNode->next;
    if (index == 0) {
        linkedListAddBeginning(list, value);
        return;
    }
    k++;
    while (curNode->next != nullptr) {
        if (k == index) {
            Node *newNode = new Node{value, curNode};
            prevNode->next = newNode;
            return;
        } else {
            k++;
            prevNode = curNode;
            curNode = curNode->next;
        }
    }
    k++;
    if (k == index) {
        linkedListAddEnd(list, value);
        return;
    } else if (index > k) {
        printf("ur index exceeds max list's index\n");
    }
}

void linkedListDeleteByIndex(LinkedList *list, int index) {
    int k = 0;
    Node *prevNode = list->first;
    Node *curNode = prevNode->next;
    if (index == 0) {
        list->first = curNode;
        delete prevNode;
        return;
    } else {
        k++;
        while (curNode->next != nullptr) {
            if (k == index) {
                prevNode->next = curNode->next;
                delete curNode;
                return;
            } else {
                k++;
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
        if (curNode->next == nullptr & k == index) {
            prevNode->next = nullptr;
            delete curNode;
            return;
        } else {
            printf("ur index exceeds max list's index\n");
        }
    }
}

void programClose(LinkedList *list) {
    linkedListShow(list);
    linkedListDelete(list);
}


int main() {
    int input = -1;
    int variant;
    int value;
    int index;
    int option;
    LinkedList list;
    linkedListCreate(&list);
    printf("1-add in the end\n"
           "2-add in the beginning\n"
           "if input = 0 -> different options:searching, deleting, adding\n");
    scanf("%i", &variant);
    switch (variant) {
        case 1:
            printf("put ur values\n");
            while (input != 0) {
                scanf("%i", &input);
                if (!input) break;
                linkedListAddEnd(&list, input);
            }
            if (input == 0) {
                printf("1-search by index\n"
                       "2-search by value\n"
                       "3-delete by index\n"
                       "4-add by index\n");
                scanf("%i", &option);
                switch (option) {
                    case 1:
                        printf("put the index to search by\n");
                        scanf("%i", &index);
                        linkedListSearchByIndex(&list, index);
                        break;
                    case 2:
                        printf("put the value to search by\n");
                        scanf("%i", &value);
                        linkedListSearchByVal(&list, value);
                        break;
                    case 3:
                        printf("put the index to delete an element by it\n");
                        scanf("%i", &index);
                        linkedListDeleteByIndex(&list, index);
                        break;
                    case 4:
                        printf("put the index to add an element by it\n");
                        scanf("%i", &index);
                        if (index < 0) {
                            printf("no such index\n");
                            break;
                        }
                        printf("put the value of ur element\n");
                        scanf("%i", &value);
                        linkedListAddByIndex(&list, index, value);
                        break;
                    default:
                        printf("u put incorrect number. program's closed.\n");
                        programClose(&list);
                        break;
                }
            }
            programClose(&list);
            break;
        case 2:
            printf("put ur values\n");
            while (input != 0) {
                scanf("%i", &input);
                if (!input) break;
                linkedListAddBeginning(&list, input);
            }
            if (input == 0) {
                printf("1-search by index\n"
                       "2-search by value\n"
                       "3-delete by index\n"
                       "4-add by index\n");
                scanf("%i", &option);
                switch (option) {
                    case 1:
                        printf("put the index to search by\n");
                        scanf("%i", &index);
                        linkedListSearchByIndex(&list, index);
                        break;
                    case 2:
                        printf("put the value to search by\n");
                        scanf("%i", &value);
                        linkedListSearchByVal(&list, value);
                        break;
                    case 3:
                        printf("put the index to delete an element by it\n");
                        scanf("%i", &index);
                        linkedListDeleteByIndex(&list, index);
                        break;
                    case 4:
                        printf("put the index to add an element by it\n");
                        scanf("%i", &index);
                        if (index < 0) {
                            printf("no such index");
                            break;
                        }
                        printf("put the value of ur element\n");
                        scanf("%i", &value);
                        linkedListAddByIndex(&list, index, value);
                        break;
                    default:
                        printf("u put incorrect number. program's closed.\n");
                        programClose(&list);
                        break;
                }
            }
            programClose(&list);
            break;
        default:
            break;
    }
    return 0;
}
