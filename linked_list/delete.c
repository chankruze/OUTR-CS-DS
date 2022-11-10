/*
Author: chankruze (chankruze@gmail.com)
Created: Thu Nov 10 2022 13:54:14 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
*/

#include <stdio.h>

#include "../lib/linked_list.h"

// 1. delete a node from end
void delete_from_end(struct node** head) {
  // if the list is empty, nothing to delete
  if (is_empty(*head)) {
    printf("[ERROR] The linked list is already empty.");
    return;
  }

  /**
   * 1. traverse upto {n}th (last) node, keeping track of curent and prev
   * 2. set {n-1}th (prev) node's next to NULL
   * 3. free the {n}th (current) node
   */

  struct node* current = *head;
  struct node* prev = *head;

  // while (temp->next->next) {
  //   temp = temp->next;
  // }

  // 1. traverse upto {n}th (last) node, keeping track of curent and prev
  while (current->next) {
    // update prev to current node
    prev = current;
    // update current to next node
    current = current->next;
  }

  // 2. set {n-1}th (prev) node's next to NULL
  prev->next = NULL;
  // 3. free the {n}th (current) node
  free(current);
}

// 2. delete a node from start
void delete_from_start(struct node** head) {
  // if the list is empty, nothing to delete
  if (is_empty(*head)) {
    printf("[ERROR] The linked list is already empty.");
    return;
  }

  /**
   * 1. update head to point to 2nd node's address
   * 2. free 1st node
   */

  struct node* first_node = *head;
  *head = first_node->next;
  free(first_node);
}

// 3. delete a node from a specific position
void delete_from_position(struct node** head, int position) {
}

// 4. delete a node after a specific node
void delete_after_node(struct node** head, int data) {
}

int main(int argc, char const* argv[]) {
  // head/start of the linked list, default NULL to represent the list is empty
  struct node* head = NULL;
  // number of nodes to create (user input), default to 0
  int n = 0;
  // ask the user to enter a number for n
  printf("How many nodes do you want to create? (i.e. 4): ");
  // save the value of n
  scanf("%d", &n);
  // create linked list
  create_linked_list(&head, n);
  // print the original linked list
  print_linked_list(head);

  // 1. delete a node from the end
  delete_from_end(&head);
  // print the new linked list
  print_linked_list(head);

  // 2. delete a node from the start
  delete_from_start(&head);
  // print the new linked list
  print_linked_list(head);

  return 0;
}
