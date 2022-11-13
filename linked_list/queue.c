/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Nov 13 2022 08:43:45 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

enum option {
  ENQUEUE = 1,
  DEQUEUE,
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
void print(struct node** front) {
  // if the queue is empty then front will be NULL
  if (*front == NULL) {
    printf("Queue is empty.\n");
    return;
  }

  struct node* current_node = *front; /* point current node to first node's address */
  int index = 1;                      /* loop counter */

  printf("------ Queue [start] ------\n");
  while (current_node != NULL) {
    printf("#%d\t[%p]\t{data = %d\t| next = %p}\n", index, current_node, current_node->data, current_node->next);
    current_node = current_node->next; /* update current node address */
    index++;                           /* update loop counter */
  }
  printf("------- Queue [end] -------\n");
}

// enqueue (same as insert node at the end of the linked list)
void enqueue(struct node** front, int data) {
  // if the queue is empty, just create a new node and
  // update the front with the new node's address
  if (*front == NULL) {
    *front = create_node(data);
    return;
  }

  struct node* rear = *front;

  // 1. traverse upto the end
  while (rear->next) {
    rear = rear->next;
  }

  // 2. create a new node
  struct node* _node = create_node(data);
  // 3. update the rear node to point to the new node
  rear->next = _node;
}

// dequeue (same as delete from the start of a linked list)
void dequeue(struct node** front) {
  // if the queue is already empty, print error
  if (*front == NULL) {
    printf("[ERROR] Queue is already empty. Can't dequeue an element.\n");
    return;
  }

  // 1. store previous first node (front pointer's value) in a temp node*
  struct node* first_node = *front;
  // 2. update the front to point to the first node's next
  *front = first_node->next;
  // 3. free the first node
  free(first_node);
}

// show the queue ops
void print_options() {
  printf("**************************\n");
  printf("* %d. enqueue\n", ENQUEUE);
  printf("* %d. dequeue\n", DEQUEUE);
  printf("* %d. print\n", PRINT);
  printf("* %d. exit\n", EXIT);
  printf("**************************\n");
}

// driver function
int main(int argc, char const* argv[]) {
  printf("**************************\n");
  printf("* STACK using LinkedList *\n");

  // node pointers for front and temp
  struct node *front = NULL, *temp = NULL;
  // choice and data for enqueue
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
      case ENQUEUE: /* enqueue new data to queue */
        printf("Enter the data to enqueue: ");
        scanf("%d", &data);
        enqueue(&front, data);
        break;
      case DEQUEUE: /* delete first data inserted into the queue */
        dequeue(&front);
        break;
      case PRINT: /* print the queue */
        print(&front);
        break;
      default: /* continue */
        break;
    }
  }

  return 0;
}
