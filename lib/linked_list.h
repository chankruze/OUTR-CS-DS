/*
Author: chankruze (chankruze@gmail.com)
Created: Wed Nov 09 2022 20:20:26 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdlib.h>

struct node {
  int data;          /* integer value */
  struct node *next; /* address of the next node */
};

void print_linked_list(struct node *head) {
  // if the linked list is empty then head will be NULL
  if (head == NULL) {
    printf("Linked list is empty.");
    return;
  }

  struct node *current_node = head; /* point current node to first node's address */
  int index = 1;                    /* loop counter */

  printf("------ Linked List [start] ------\n");
  while (current_node != NULL) {
    printf("#%d\t[%p]\t{data = %d\t| next = %p}\n", index, current_node, current_node->data, current_node->next);
    current_node = current_node->next; /* update current node address */
    index++;                           /* update loop counter */
  }
  printf("------- Linked List [end] -------\n");
}

struct node *create_node(int data) {
  struct node *_node = malloc(sizeof(struct node));
  _node->data = data;
  _node->next = NULL;
  return _node;
}

int is_empty(struct node *head) {
  return head == NULL;
}

void print_node(struct node *_node) {
  printf("node {data = %d, next = %p}\n", _node->data, _node->next);
}
