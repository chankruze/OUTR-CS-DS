/*
Author: chankruze (chankruze@gmail.com)
Created: Thu Dec 08 2022 20:01:07 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"

void forward_traverse(struct node *node) {
  if (node) {
    print_node(node);
    forward_traverse(node->next);
  }
}

void backward_traverse(struct node *node) {
  if (node) {
    backward_traverse(node->next);
    print_node(node);
  }

  return;
}

int main() {
  // initialize nodes
  struct node *head;
  struct node *node1 = NULL;
  struct node *node2 = NULL;
  struct node *node3 = NULL;
  struct node *node4 = NULL;

  // allocate memory
  node1 = malloc(sizeof(struct node));
  node2 = malloc(sizeof(struct node));
  node3 = malloc(sizeof(struct node));
  node4 = malloc(sizeof(struct node));

  // assign data values
  node1->data = 10;
  node2->data = 20;
  node3->data = 30;
  node4->data = 40;

  // link the nodes
  head = node1;        /* store address of first node in head */
  node1->next = node2; /* store address of 2nd node in 1st node's next */
  node2->next = node3; /* store address of 3rd node in 2nd node's next */
  node3->next = node4; /* store address of 4th node in 3rd node's next */
  node4->next = NULL;  /* store NULL in 4th node's next */

  // traverse the linked list in forward direction
  printf("--- Forward Travesing ---\n");
  forward_traverse(head);
  printf("\n");
  // traverse the linked list in backward direction
  printf("--- Backward Travesing ---\n");
  backward_traverse(head);
  printf("\n");

  return 0;
}