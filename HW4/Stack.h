#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack{
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push(string newItem);
    bool pop();
    bool pop(string &topItem);
    bool getTop(string &topItem) const;

private:
    struct StackNode {
        string item;
        StackNode *next;
    };
    StackNode *head;
};