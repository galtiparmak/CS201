#include <iostream>
#include <string>
using namespace std;

#include "Stack"
#include "AlgebraicExpression.h"

int main() {
    AlgebraicExpression alb;
    string s = "x+y*z/w+u";
    cout << alb.infix2postfix(s);
    return 0;
}