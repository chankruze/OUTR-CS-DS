/*
Author: chankruze (chankruze@gmail.com)
Created: Fri Nov 11 2022 20:27:36 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

enum option {
  PUSH = 1,
  POP,
  PRINT,
  EXIT,
};

struct node* create_node(int data) {
  struct node* n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  return n;
}

// print
void print(struct node** top) {
  // if the stack is empty then top will be NULL
  if (*top == NULL) {
    printf("Stack is empty.\n");
    return;
  }

  struct node* current_node = *top; /* point current node to first node's address */
  int index = 1;                    /* loop counter */

  printf("------ Stack [start] ------\n");
  while (current_node != NULL) {
    printf("#%d\t[%p]\t{data = %d\t| next = %p}\n", index, current_node, current_node->data, current_node->next);
    current_node = current_node->next; /* update current node address */
    index++;                           /* update loop counter */
  }
  printf("------- Stack [end] -------\n");
}

// push
void push(struct node** top, int data) {
  // if the stack is empty, just create a new node and
  // update the top with the new node's address
  if (*top == NULL) {
    *top = create_node(data);
    return;
  }

  // 1. create a new node
  struct node* _node = create_node(data);
  // 2. update the new node to point to the previous first node (top pointer's value)
  _node->next = *top;
  // 3. update the top to point to the new node's location
  *top = _node;
}

// pop
void pop(struct node** top) {
  // if the stack is already empty, print error
  if (*top == NULL) {
    printf("[ERROR] Stack is already empty. Can't pop an element.\n");
    return;
  }

  // 1. store previous first node (top pointer's value) in a temp node*
  struct node* first_node = *top;
  // 2. update the top to point to the first node's next
  *top = first_node->next;
  // 3. free the first node
  free(first_node);
}

// show the stack ops
void print_options() {
  printf("**************************\n");
  printf("* %d. push\n", PUSH);
  printf("* %d. pop\n", POP);
  printf("* %d. print\n", PRINT);
  printf("* %d. exit\n", EXIT);
  printf("**************************\n");
}

// driver function
int main(int argc, char const* argv[]) {
  printf("**************************\n");
  printf("* STACK using LinkedList *\n");

  // node pointers for top and temp
  struct node *top = NULL, *temp = NULL;
  // choice and data for push
  int opt, data;

  // loop until the user chooses to EXIT
  while (opt != EXIT) {
    // show options
    print_options();
    // prompt to enter the option
    printf("option>");
    // read the option and store in opt variable
    scanf("%d", &opt);

    switch (opt) {
      case PUSH: /* push new data to stack */
        printf("Enter the data to push: ");
        scanf("%d", &data);
        push(&top, data);
        break;
      case POP: /* delete last data inserted into the stack */
        pop(&top);
        break;
      case PRINT: /* print the stack */
        print(&top);
        break;
      default: /* continue */
        break;
    }
  }

  return 0;
}
