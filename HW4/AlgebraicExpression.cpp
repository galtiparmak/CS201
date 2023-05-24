#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"
#include "AlgebraicExpression.h"

bool AlgebraicExpression::isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return true;
    }
    return false;
}

int AlgebraicExpression::priority(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

bool AlgebraicExpression::isOperand(char ch) {
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
        return true;
    }
    return false;
}

//string AlgebraicExpression::infix2prefix(const string exp) {

//}

string AlgebraicExpression::infix2postfix(const string exp) {
    string str = '(' + exp + ')';
    int size = str.size();
    Stack stack;
    string result;
    string top;

    for (int i = 0; i < size; i++) {
        string current = str.substr(i,1);
        if (isOperand(str[i])) {
            result += str[i];
        }
        else if (str[i] == '(') {
            stack.push(current);
        }
        else if (str[i] == ')') {
            bool res = false;
            while (!res) {
                stack.getTop(top);
                if (top != "(") {
                    result += top;
                    stack.pop();
                }
                else {
                    stack.pop();
                    res = true;
                }
            }
        }
        else {
            stack.getTop(top);
            if (isOperator(top[0])) {
                while (priority(current[0]) <= priority(top[0])) {
                    stack.getTop(top);
                    result += top;
                    stack.pop();
                }
                stack.push(current);
            }
        }
    }
    while(!stack.isEmpty()) {
        stack.getTop(top);
        result += top;
        stack.pop();
    }
    return result;
}
