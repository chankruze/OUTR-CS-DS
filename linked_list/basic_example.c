/*
Author: chankruze (chankruze@gmail.com)
Created: Wed Nov 09 2022 20:29:24 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"

int main(int argc, char const *argv[]) {
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

  // print the linked list
  print_linked_list(head);

  return 0;
}
