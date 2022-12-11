/*
Author: chankruze (chankruze@gmail.com)
Created: Thu Dec 08 2022 19:21:57 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"

void reverse_linked_list(struct node **head) {
  // if the list is empty print error
  if (*head == NULL) {
    printf("[ERROR] The list is empty.\n");
    return;
  }

  struct node *current = *head, *prev = NULL, *next;

  while (current) {
    // store the original next link
    next = current->next;
    // update current->next to prev
    current->next = prev;
    // update node *prev to current node's address
    prev = current;
    // update current to next original node's address
    current = next;
  }

  // update the head to point to the first node (originally last node)
  *head = prev;
}

// using recursion
void reverse_linked_list_recursion(struct node **head, struct node *node) {
  // if the list is empty print error
  if (node->next == NULL) {
    *head = node;
    return;
  }

  reverse_linked_list_recursion(head, node->next);
  struct node *temp = node->next;
  temp->next = node;
  node->next = NULL;
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

  // print the linked list
  print_linked_list(head);
  // reverse the linked list using iterative method
  reverse_linked_list(&head);
  // print reversed linked list
  print_linked_list(head);
  // reverse using recursion
  reverse_linked_list_recursion(&head, head);
  // print reversed linked list
  print_linked_list(head);

  return 0;
}