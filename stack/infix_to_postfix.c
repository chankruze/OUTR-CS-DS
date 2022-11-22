/*
Author: chankruze (chankruze@gmail.com)
Created: Mon Nov 14 2022 21:55:11 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

char* stack(int size) {
  char stack[size];
  return stack;
}

int main(int argc, char const* argv[]) {
  char expr[MAX_SIZE];

  printf("Enter the prefix expression: ");
  scanf("%s", expr);

  for (int i = 0; i < MAX_SIZE; i++) {
    if (!expr[i]) {
      expr[i] = ')';
      break;
    }
  }

  printf("Infix expression: %s\n", expr);

  // stack
  char* stk = stack(50);

  /**
   * Traverse the infix expression
   *
   * if ( found -> push into stack
   * if operand -> print it
   * if ) found -> keep popping from stack and print till ( is found
   * if operator -> if stack is empty, push.
   *                else compare with the top operator in the stack,
   *                     if higher precedence, push
   *                     else keep popping the stack and print till lower precedence operator is found.
   * once the expression is finished, keep popping from stack and print.
   *
   */

  return 0;
}
