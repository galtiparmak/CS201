#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

Stack::Stack() {
    head = NULL;
}

Stack::Stack(const Stack& aStack) {
    if (aStack.head == NULL) {
        head = NULL;
    }
    else {
        head = new StackNode;
        head->item = aStack.head->item;
        StackNode *newptr = head;
        for (StackNode *temp = aStack.head->next; temp != NULL; temp = temp->next) {
            newptr->next = new StackNode;
            newptr = newptr->next;
            newptr->item = temp->item;
        }
        newptr->next = NULL;
    }
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const{
    return head == NULL;
}

bool Stack::push(string newItem) {
    StackNode *newItemPtr = new StackNode;
    newItemPtr->item = newItem;
    newItemPtr->next = head;
    head = newItemPtr;
    return true;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    else {
        StackNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool Stack::pop(string &topItem) {
    if (isEmpty()) {
        return false;
    }
    else{
        topItem = head->item;
        StackNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool Stack::getTop(string &topItem) const {
    if (isEmpty()) {
        return false;
    }
    else {
        topItem = head->item;
        return true;
    }
}