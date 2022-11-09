/*
Author: chankruze (chankruze@gmail.com)
Created: Wed Nov 09 2022 20:20:26 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdlib.h>

struct node {
  int data;          /* data: integer value */
  struct node *next; /* next: address of the next node */
};

void print_linked_list(struct node *head) {
  // if the linked list is empty then head will be NULL
  if (head == NULL) {
    printf("Linked list is empty.");
    return;
  }

  struct node *current_node = head; /* point current node to first node's address */
  int index = 1;                    /* loop counter */

  while (current_node != NULL) {
    printf("node %d {data = %d | next = %p}\n", index, current_node->data, current_node->next);
    current_node = current_node->next; /* update current node address */
    index++;                           /* update loop counter */
  }
}