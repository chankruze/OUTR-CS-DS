/*
Author: chankruze (chankruze@gmail.com)
Created: Thu Dec 08 2022 20:48:31 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  string expr;
  stack<char> stk;

  cout << "Enter an expression: ";
  cin >> expr;

  for (int i = 0; i < expr.length(); i++) {
    char c = expr.at(i);
    switch (c) {
      case '[':
      case '(':
      case '{':
        stk.push(c);
        break;
      case ')':
        // check if the top of stack is opening (
        if (stk.top() == '(') stk.pop();
        break;
      case '}':
        // check if the top of stack is opening {
        if (stk.top() == '{') stk.pop();
        break;
      case ']':
        // check if the top of stack is opening [
        if (stk.top() == '[') stk.pop();
        break;
    }
  }

  if (stk.size()) {
    cout << stk.size() << "Expression doesn't have balanced parenthesis" << endl;
    return 0;
  }

  cout << "Expression has balanced parenthesis" << endl;
  return 0;
}